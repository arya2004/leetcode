package sheet.binary_search;

//Time complexity: O(n + m)
//Space complexity: O(1)


/*
 * 
 * Approach:
 * 1. Start from the top right corner of the matrix.
 * 2. If the target is equal to the element at the top right corner, return true.
 * 3. If the target is greater than the element at the top right corner, move to the next row.
 * 4. If the target is less than the element at the top right corner, move to the previous column.
 * 5. If the target is not found, return false.
 * 
 * 
 * 
 */



public class search_a_2d_matrix_ii {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0) {
            if(matrix[row][col] == target){
                return true;
            } else if(matrix[row][col] < target){
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
}
