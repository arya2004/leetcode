package LeetCode.daily;

import java.util.*;

public class k_th_smallest_in_lexicographical_order {
    public int findKthNumber(int n, int k) {
        long current = 1;
        int index = 1;

        while (index < k) {
            long steps = count(n, k, current);

            if(index + steps <= k){
                current++;
                index += steps;
            } 
            else{ 
                current *= 10;
                index++;
            }
        }
        
        return (int)current;
        
    }
    public long count(int n, int k, long current){
        int result = 0;

        long neighboir = current + 1;

        while (current <= n) {
            neighboir = Math.min(neighboir, n + 1);
            result += neighboir - current;
            current *= 10;
            neighboir *= 10;
        }

        return result;
    }

   
    public int TLL(int n, int k) {
        Integer[] arr = new Integer[n];
        for(int i = 1; i <= n; i++){
            arr[i -1] = i;
        }

        Arrays.sort(arr, (a,b) -> a.toString().compareTo(b.toString()));

        return arr[k -1];
    }
}
