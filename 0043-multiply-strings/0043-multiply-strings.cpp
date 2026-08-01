class Solution {
public:
    string multiply(string num1, string num2) {

        // If either number is 0,
        // the product is always 0.
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        // The maximum number of digits in the product
        // can be at most m + n.
        vector<int> result(m + n, 0);

        // Traverse both strings from right to left,
        // just like manual multiplication.
        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                // Convert characters to digits.
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                // Multiply the two digits.
                int product = digit1 * digit2;

                // Positions where the result and carry go.
                int p1 = i + j;
                int p2 = i + j + 1;

                // Add the current product to any value
                // already present at position p2.
                int sum = product + result[p2];

                // Store the current digit.
                result[p2] = sum % 10;

                // Add the carry to the previous position.
                result[p1] += sum / 10;
            }
        }

        // Build the final answer.
        string ans = "";

        // Skip leading zeros.
        int i = 0;
        while (i < result.size() && result[i] == 0)
            i++;

        // Convert digits to characters.
        while (i < result.size()) {
            ans += (result[i] + '0');
            i++;
        }

        return ans;
    }
};