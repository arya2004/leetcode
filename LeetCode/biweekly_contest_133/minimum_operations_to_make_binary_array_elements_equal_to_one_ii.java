package LeetCode.biweekly_contest_133;

public class minimum_operations_to_make_binary_array_elements_equal_to_one_ii {
    public int minOperationsTLL(int[] nums) {
        int flips = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                flips++;
                for (int j = i; j < n; j++) {
                    nums[j] = 1 - nums[j];
                }
            }
        }
        
        return flips;
    }
    //non tll
    public int minOperations(int[] nums) {
        int flips = 0;
        boolean flipped = false;

        for (int num : nums) {
            if ((num ^ (flipped ? 1 : 0)) == 0) {
                flips++;
                flipped = !flipped;
            }
        }
        
        return flips;
    }
}
