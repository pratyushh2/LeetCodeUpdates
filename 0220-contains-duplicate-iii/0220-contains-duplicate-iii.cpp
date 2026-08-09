class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        // Sorted set containing values from the
        // current sliding window.
        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {

            // Remove the element that is now too far away.
            //
            // We only want indices j such that:
            // i - j <= indexDiff
            //
            // Therefore, index i-indexDiff-1
            // is no longer allowed.
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            // We need a value x such that:
            //
            // |nums[i] - x| <= valueDiff
            //
            // This is equivalent to:
            //
            // nums[i] - valueDiff <= x
            // x <= nums[i] + valueDiff
            long long lower = (long long)nums[i] - valueDiff;
            long long upper = (long long)nums[i] + valueDiff;

            // Find the first value >= lower.
            auto it = window.lower_bound(lower);

            // If such a value exists and it is also
            // <= upper, then its value difference
            // is within valueDiff.
            if (it != window.end() && *it <= upper) {
                return true;
            }

            // Add the current value to the window
            // for future indices.
            window.insert(nums[i]);
        }

        // No valid pair was found.
        return false;
    }
};