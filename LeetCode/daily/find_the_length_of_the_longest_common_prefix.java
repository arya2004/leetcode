package LeetCode.daily;

import java.util.*;

public class find_the_length_of_the_longest_common_prefix {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        HashSet<Integer> hs = new HashSet<>();
        for (int i = 0; i < arr2.length; i++) {
            
            int temp = arr2[i];

            while (temp >= 0 && !hs.contains(temp)) {
                
                    hs.add(temp);
                    temp = temp / 10;
                
            }
            
            
        }

        int result = 0;

        for (int i = 0; i < arr1.length; i++) {
            Integer temp = arr1[i];
            while (temp >= 0 && !hs.contains(temp)) {
                temp = temp / 10;
            }

            if(hs.contains(temp)){
                result = Math.max(result, temp.toString().length());
            }
        }


        return result;

    }
}
