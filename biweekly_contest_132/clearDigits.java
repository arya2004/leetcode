package biweekly_contest_132;


import java.util.*;


class Solution {
    public String clearDigits(String s) {
        StringBuilder sb = new StringBuilder(s);

        while (containsDigit(sb)) {
            for (int i = 0; i < sb.length(); i++) {
                if (Character.isDigit(sb.charAt(i))) {
                    for (int j = i - 1; j >= 0; j--) {
                        if (!Character.isDigit(sb.charAt(j))) {
                            sb.deleteCharAt(i);  
                            sb.deleteCharAt(j); 
                            break;
                        }
                    }
                    break;
                }
            }
        }

        return sb.toString();
    }
    private static boolean containsDigit(StringBuilder sb) {
        for (int i = 0; i < sb.length(); i++) {
            if (Character.isDigit(sb.charAt(i))) {
                return true;
            }
        }
        return false;
    }
}