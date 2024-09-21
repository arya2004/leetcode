package LeetCode.daily;

import java.util.*;

public class lexicographical_numbers {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> l = new ArrayList<Integer>();

        for (int i = 1; i <= n; i++) {
            l.add(i);
        }
     

        l.sort( (a,b) -> a.toString().compareTo(b.toString()));

        return l;

    }
}
