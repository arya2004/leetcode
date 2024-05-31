package sheet.strings;

import java.util.*;

public class reverse_words_in_a_string {
    public String reverseWords(String s) {
        Stack<String> st = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != ' ' && sb.length() != 0){
                sb.append(s.charAt(i));
            }
            if(s.charAt(i) != ' ' && sb.length() == 0){
                sb.append(s.charAt(i));
            }
            if(s.charAt(i) == ' ' && sb.length() == 0){
                continue;
            }
            if(s.charAt(i) == ' ' && sb.length() != 0){
                st.push(sb.toString());
                sb.delete(0, sb.length() );
            }
             
            
        }
        st.push(sb.toString());
        StringBuilder ssb = new StringBuilder();
        while (!st.isEmpty()) {
            ssb.append(st.peek());
            st.pop();
            ssb.append(' ');
        }
        
        return ssb.toString().trim();
    }
}
