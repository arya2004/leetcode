package LeetCode.biweekly_contest_133;

import java.util.*;

public class find_minimum_operations_to_make_all_elements_divisible_by_three {
    public int minimumOperations(int[] nums) {
        int nunOperations  = 0;
        for (int num : nums) {
            
            nunOperations += Math.min(num % 3, 3 - (num % 3));
        }

        return nunOperations;
    }
}
