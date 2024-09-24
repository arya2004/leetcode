package LeetCode.daily;

import java.util.*;


public class extra_characters_in_a_string {

    int[] dp = new int[50];

    public int minExtraChar(String s, String[] dictionary) {
        int n = s.length();
        Arrays.fill(dp, -1);
        HashSet<String> dict = new HashSet<>(Arrays.asList(dictionary));
        return rec(s, dict, 0);
    }

    public int rec(String s, HashSet<String> dict, int index){
        
        if(index == s.length()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        StringBuilder sb = new StringBuilder();
        int minExtraChar = Integer.MAX_VALUE;

        for (int i = index; i < s.length(); i++) {
            sb.append(s.charAt(i));
            int extraChar = 0;
            if(!dict.contains(sb.toString())){
                extraChar = sb.length();
            }

            int curExtra = rec(s, dict, i + 1);
            minExtraChar = Math.min(minExtraChar, curExtra + extraChar);
        }

        dp[index] = minExtraChar;

        return minExtraChar;
    }
}
