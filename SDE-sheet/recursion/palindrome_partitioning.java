import java.util.ArrayList;
import java.util.List;

public class palindrome_partitioning {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> paList = new ArrayList<>();
        rec(0,s, paList, res);
        return res;
    }

    boolean isPalindrome(String s, int start, int end){
        while (start <= end) {
            if(s.charAt(start) != s.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void rec(int index, String s, List<String> path, List<List<String>> result){
        if(index == s.length()){
            result.add(new ArrayList<>(path) );
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if(isPalindrome(s, index, i)){
                path.add(s.substring(index, i + 1));
                rec(i + 1, s, path, result);
                path.remove(path.size() - 1);
            }
        }
    }
}
