package Codeforces;
import java.util.*;
 
public class C1947 {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        List<String> results = new ArrayList<>();
        
     
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            String b = scanner.next();
            results.add(decodeString(b));
        }
        
        for (String result : results) {
            System.out.println(result);
        }
        
        scanner.close();
    }
    
    private static String decodeString(String encoded) {
        Set<Character> uniqueChars = new TreeSet<>();
        for (char c : encoded.toCharArray()) {
            uniqueChars.add(c);
        }
        
        List<Character> rList = new ArrayList<>(uniqueChars);
        int n = rList.size();
        
        Map<Character, Character> mapping = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mapping.put(rList.get(i), rList.get(n - 1 - i));
        }
        
        StringBuilder decoded = new StringBuilder();
        for (char c : encoded.toCharArray()) {
            decoded.append(mapping.get(c));
        }
        
        return decoded.toString();
    }
}