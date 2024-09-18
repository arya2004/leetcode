package LeetCode.daily;

import java.util.*;

public class largest_number {
    public String largestNumber(int[] nums) {


        String[] s = new String[nums.length];
         for (int i = 0; i < nums.length; i++) {
             s[i] = String.valueOf(nums[i]);
         }
 
         Arrays.sort(s, (a, b) -> (b + a).compareTo(a + b));
         if (s[0].equals("0")) {
             return "0";
         }
         
         
         StringBuilder sb = new StringBuilder();
         for (String i : s) {
             sb.append(i);
         }
 
         return sb.toString();
     }
}
