import java.util.*;

public class subsets_ii {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        findSubset(0, nums, new ArrayList<>(), ans);
        return ans;
    }

    public void findSubset(int index, int[] nums, List<Integer> ds, List<List<Integer>> ansList){
        ansList.add(new ArrayList<>(ds));
        for (int i = index; i < nums.length; i++) {
            if(i != index && nums[i] == nums[i - 1]) continue;
            ds.add(nums[i]);
            findSubset(i + 1, nums, ds, ansList);
            ds.remove(ds.size() - 1);
        }
    }
}
