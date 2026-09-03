class Solution {
    public int[] twoSum(int[] nums, int target) {

        // HashMap stores:
        // number -> index
        HashMap<Integer, Integer> map = new HashMap<>();

        // Go through every element.
        for (int i = 0; i < nums.length; i++) {

            // We need another number such that:
            //
            // nums[i] + complement = target
            //
            // Therefore:
            // complement = target - nums[i]
            int complement = target - nums[i];

            // Check whether we have already seen
            // the required complement.
            if (map.containsKey(complement)) {

                // The complement was found earlier.
                // Return its index and the current index.
                return new int[]{
                    map.get(complement),
                    i
                };
            }

            // We haven't found the pair yet,
            // so store the current number and its index.
            map.put(nums[i], i);
        }

        // The problem guarantees a solution,
        // but return an empty array if none exists.
        return new int[]{};
    }
}