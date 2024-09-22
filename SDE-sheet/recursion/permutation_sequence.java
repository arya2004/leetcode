import java.util.ArrayList;
import java.util.List;

public class permutation_sequence {
    public String getPermutation(int n, int k) {
        int factorial = 1;
        List<Integer> numbers = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            factorial *= i;
            numbers.add(i);
        }

        numbers.add(n);
        String ans = "";
        k--;
        while (true) {
            ans = ans + (numbers.get(k / factorial)).toString();
            numbers.remove(k / factorial);
            if(numbers.size() == 0){
                break;
            }
            k = k % factorial;
            factorial = factorial / numbers.size();
        }
        return ans;
    } 
}
