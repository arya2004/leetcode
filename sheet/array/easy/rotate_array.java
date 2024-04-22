package sheet.array.easy;

//time complexity O(n)
//space complexity O(1)
/*
 * 
 * Algorithm: 
 * 1. Reverse the entire array
 * 2. Reverse the first k elements
 * 3. Reverse the remaining elements
 * 
 * 
 */


public class rotate_array {
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
   public void reverse(int[] nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
    }

}
