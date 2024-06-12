
package Codeforces.contest;

import java.util.*;
 
public class cf {

 
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 0; i < t; i++) {
            String a = s.next();
            String b = s.next();
            StringBuilder sba = new StringBuilder(a);
            StringBuilder sbb = new StringBuilder(b);
            sba.deleteCharAt(0);
            sbb.deleteCharAt(0);
            System.out.println(b.charAt(0) +  sba.toString() + " " + a.charAt(0) + sbb.toString());
            
        }
    }
}
