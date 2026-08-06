class Solution {
public:
    bool canJump(vector<int>& nums) {

        // maxReach stores the farthest index
        // we can reach so far.
        int maxReach = 0;

        // Traverse every index.
        for (int i = 0; i < nums.size(); i++) {

            // If the current index is beyond
            // our farthest reachable position,
            // then this index is unreachable.
            if (i > maxReach)
                return false;

            // Update the farthest reachable index.
            maxReach = max(maxReach, i + nums[i]);

            // If we can already reach or cross
            // the last index, no need to continue.
            if (maxReach >= nums.size() - 1)
                return true;
        }

        // Finished traversing the array.
        return true;
    }
};