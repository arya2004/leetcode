package sheet.sliding_window.medium;

public class longest_substring_without_repeating_characters {
    
    // 2 pointer and sliding window problem
    
    public int lengthOfLongestSubstring(String s) {
       
        int n = s.length();
        int[] freq = new int[256];
        for (int i = 0; i < 256; i++) {
            freq[i] = -1;
        }

        int l = 0;
        int r = 0;
        int max_len = - 0;

        while (r < n) {
            
            if(freq[s.charAt(r)] != -1){

                if(freq[s.charAt(r)] >= l){
                    l = freq[s.charAt(r)] + 1;
                }

            }
            max_len = Math.max(max_len, r - l + 1);

            freq[s.charAt(r)] = r;
            r++;

        }

        return max_len;
    }
}
