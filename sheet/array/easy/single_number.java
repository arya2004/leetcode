package sheet.array.easy;


// Time complexity: O(n)
// Space complexity: O(1)

/*
 * Algorithm:
 * 1. Initialize a variable xor to 0
 * 2. Iterate over the array
 * 3. Perform xor operation with the element at the current index
 * 4. Return the xor value
 * 
 * 
 * Why xor operation?
 * 
 * 
 */


public class single_number {
    public int singleNumber(int[] nums) {
        int n = nums.length;
        int xor = 0;
        for (int i = 0; i < n; i++) {
            xor = xor ^ nums[i];
        }

        return xor;
    }
}
