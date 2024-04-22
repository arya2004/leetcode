package sheet.array.easy;

public class check_if_array_is_sorted_and_rotated {
    public boolean check(int[] nums) {
          int steps = 0;
        for (int i = 0; i < nums.length && steps <= 2; i++)
        {
            if (nums[i] > nums[(i + 1) % nums.length])
            {
                steps = steps + 1;
            }
        }
        return steps >1? false: true;
}
}
