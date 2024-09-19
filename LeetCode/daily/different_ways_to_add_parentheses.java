package LeetCode.daily;

import java.util.*;



public class different_ways_to_add_parentheses {
     public List<Integer> diffWaysToCompute(String expression) {
        return rec(expression, 0, expression.length() - 1);
    }


    public List<Integer> rec(String exp, int start, int end){

        List<Integer> res = new ArrayList<>();

        //single digit base case

        if(start == end){
            res.add(exp.charAt(start) - '0');
            return res;
        }

        if(end  == 1 + start && Character.isDigit(exp.charAt(start))){

            int n1 = exp.charAt(start) - '0';
            int n2 = exp.charAt(end) - '0';
            int num = n1 * 10 + n2;
            res.add(num);
            return res;

        }

        for (int i = start; i <= end; i++) {
            if(Character.isDigit(exp.charAt(i))){
                continue;
            }

            char op = exp.charAt(i);

            List<Integer> left = rec(exp, start, i -1);
            List<Integer> right = rec(exp, i + 1, end);

            for (int l : left) {
                for (int r : right) {
                    if(op == '*') res.add(l*r);
                    else if(op == '+') res.add(l+r);
                    else res.add(l-r);
                    
                }
            }
        }

        return res;


    }
}
