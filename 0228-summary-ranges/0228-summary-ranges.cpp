class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        // Stores the final list of ranges.
        vector<string> ans;

        int n = nums.size();

        // Traverse every number in the array.
        for (int i = 0; i < n; i++) {

            // Mark the beginning of the current range.
            int start = nums[i];

            // Keep moving while the next number
            // is exactly one greater than the current number.
            while (i + 1 < n &&
                   (long long)nums[i + 1] == (long long)nums[i] + 1) {

                i++;
            }

            // nums[i] is now the last number of this range.
            int end = nums[i];

            // If start and end are the same,
            // this range contains only one number.
            if (start == end) {

                ans.push_back(to_string(start));
            }
            else {

                // Otherwise store it as "start->end".
                ans.push_back(to_string(start) + "->" + to_string(end));
            }
        }

        return ans;
    }
};