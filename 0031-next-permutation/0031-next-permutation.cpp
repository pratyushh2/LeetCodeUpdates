class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // Step 1:
        // Find the first index from the right
        // where nums[i] is smaller than nums[i+1].
        // This is called the pivot.
        int pivot = -1;

        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2:
        // If a pivot exists,
        // find the first element from the right
        // that is greater than the pivot.
        if (pivot != -1) {

            for (int i = n - 1; i > pivot; i--) {

                if (nums[i] > nums[pivot]) {

                    // Swap them.
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
        }

        // Step 3:
        // Reverse everything after the pivot.
        // If no pivot existed,
        // this reverses the entire array.
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};