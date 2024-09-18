import java.util.*;

class Solution {
    public String largestNumber(int[] nums) {

        String[] s = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            s[i] = String.valueOf(nums[i]);
        }

        Arrays.sort(s, (a, b) -> (a + b).compareTo(b + a));
        
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