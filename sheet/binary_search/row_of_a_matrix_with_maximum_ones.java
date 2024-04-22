
package sheet.binary_search;

import java.util.*;


public class row_of_a_matrix_with_maximum_ones {

    private static int lowerBound(ArrayList<Integer> a, int n, int x){
        int low = 0;
        int high = n -1;
        int ans = n;
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            if(a.get(mid) >= x){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public static int maximumOnesRow(ArrayList<ArrayList<Integer>> matrix, int n, int m)
    {
        //	  Write your code here.
        int maxi = -1;
        int index = -1;
        for (int i = 0; i < matrix.size(); i++) {
            
            int total_ones = m - lowerBound(matrix.get(i), m, 1);
            if(total_ones > maxi){
                maxi = total_ones;
                index = i;
            }
        }
        return index;
    }
}
