package sheet.array.easy;

public class max_consecutive_ones {
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int n = nums.length;
        int max = 0;
        int current_count = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
            {
                current_count++;
                max = Math.max(max, current_count);
            }
            else
            {
                current_count = 0;
            }
        }
        return max;
    }
}
