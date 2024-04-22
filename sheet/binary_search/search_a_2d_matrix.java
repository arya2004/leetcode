package sheet.binary_search;

//Time complexity: O(log(n*m))
//Space complexity: O(1)

/*
 * Algorithm:
 * 1. Find the number of rows and columns in the matrix.
 * 2. Apply binary search on the matrix.
 * 3. low = 0, high = n*m - 1
 * 4. mid = (high - low) / 2 + low
 * 5. If matrix[mid / m][mid % m] == target, return true.
 * 6. If matrix[mid / m][mid % m] < target, low = mid + 1
 * 7. If matrix[mid / m][mid % m] > target, high = mid - 1
 * 8. If the target is not found, return false.
 * 
 * Approach:
 * 1. The matrix is sorted row-wise.
 * 2. So, we can apply binary search on the matrix.
 * 3. We can convert the 2D matrix into a 1D matrix.
 * 4. We can find the row and column of the mid element using mid / m and mid % m.
 * 
 * 
 */




public class search_a_2d_matrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int low = 0;
        int high = n * m - 1;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if(matrix[mid / m][mid % m] == target){
                return true;
            } else if(matrix[mid / m][mid % m] < target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
}
