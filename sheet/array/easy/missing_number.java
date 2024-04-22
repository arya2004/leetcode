package sheet.array.easy;

public class missing_number {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int total_sum = n * (n + 1) / 2;
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        return total_sum - sum;
    }
}
