package LeetCode.biweekly_contest_133;

public class minimum_operations_to_make_binary_array_elements_equal_to_one_i {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int operations = 0;
        
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {

                nums[i] = 1;
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
                operations += 1;
            }
        }
        

        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            return -1;
        }
        
        return operations;
    }
}
