package sheet.array.easy;

//Time: O(n)
//Space: O(1)

/* 
 * 
 * Algorithm:
 * 1. Initialize two pointers i and j to 0
 * 2. Iterate over the array
 * 3. If the element at i is not zero, swap the element at i with the element at j
 * 4. Increment i and j
 * 5. Continue the process until i reaches the end of the array
 * 
 */

public class move_zeroes {
    public void moveZeroes(int[] nums) {
        int j = 0;
        int i = 0;
        while(i < nums.length){
            if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
            i++;
        }
    }
}
