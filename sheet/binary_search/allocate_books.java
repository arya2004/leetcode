package sheet.binary_search;
import java.util.*;

public class allocate_books {
    public static int findPages(ArrayList<Integer> arr, int n, int m) {
      if(n < m) return -1;
      int min = 0;
      int max = 0;
      for(int i = 0; i < n; i++) {
        max += arr.get(i);
        min = Math.max(min, arr.get(i));
      }
      for (int i = min; i < max; i++) {

        int allocated = helper(arr, i);
        if(allocated == m) return i;
            
      }

      return -1;

    }

    private static int helper(ArrayList<Integer> arr, int i){
        int student = 1;
        int pageStudent = 0;
        for (int j = 0; j < arr.size(); j++) {
            if(pageStudent + arr.get(j) <= i){
                pageStudent += arr.get(j);
            }else{
                student++;
                pageStudent = arr.get(j);
            }
        }
        return student;
    }
}
