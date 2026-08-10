class Solution {
public:

    // Fenwick Tree / Binary Indexed Tree.
    // It helps us find how many unused positions
    // exist before a particular index.
    class Fenwick {
    public:

        vector<int> tree;

        Fenwick(int n) {
            tree.resize(n + 1, 0);
        }

        // Add 'value' at index i.
        // value = 1 means the position is available.
        // value = -1 means we have already used it.
        void update(int i, int value) {

            // Fenwick Tree uses 1-based indexing,
            // so convert our 0-based index to 1-based.
            i++;

            while (i < tree.size()) {

                tree[i] += value;

                // Move to the next Fenwick Tree node.
                i += i & -i;
            }
        }

        // Returns the number of available positions
        // from index 0 through index i.
        int query(int i) {

            i++;

            int sum = 0;

            while (i > 0) {

                sum += tree[i];

                // Move to the parent node.
                i -= i & -i;
            }

            return sum;
        }
    };

    string minInteger(string num, int k) {

        int n = num.size();

        // Store the original positions of every digit.
        //
        // positions[0] = positions of digit '0'
        // positions[1] = positions of digit '1'
        // ...
        vector<queue<int>> positions(10);

        for (int i = 0; i < n; i++) {

            int digit = num[i] - '0';

            positions[digit].push(i);
        }

        // Initially every position is available.
        Fenwick bit(n);

        for (int i = 0; i < n; i++) {

            bit.update(i, 1);
        }

        string ans = "";

        // Construct the answer one digit at a time.
        for (int i = 0; i < n; i++) {

            // Try the smallest possible digit first.
            for (int digit = 0; digit <= 9; digit++) {

                // No unused occurrence of this digit.
                if (positions[digit].empty())
                    continue;

                // Get the earliest unused occurrence.
                int pos = positions[digit].front();

                // Count how many unused digits are before
                // this digit in the current arrangement.
                //
                // query(pos) includes the digit itself,
                // so subtract 1.
                int cost = bit.query(pos) - 1;

                // If we can move this digit to the current
                // position using our remaining swaps,
                // choose it.
                if (cost <= k) {

                    // Spend the required swaps.
                    k -= cost;

                    // Add the chosen digit to the answer.
                    ans += char('0' + digit);

                    // This occurrence has now been used.
                    positions[digit].pop();

                    // Remove its original position from
                    // the Fenwick Tree.
                    bit.update(pos, -1);

                    // We have chosen the digit for this
                    // position, so move to the next position.
                    break;
                }
            }
        }

        return ans;
    }
};