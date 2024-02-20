#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>



using namespace std;
//

vector<vector<int>> rec(int index, vector<int>& nums, vector<int>& answer) {
    if (index >= nums.size()) {
        return {answer};
    }
    vector<vector<int>> result;
    answer.push_back(nums[index]);
    auto take = rec(index + 1, nums, answer); //take
    result.insert(result.end(), take.begin(), take.end());
    answer.pop_back();
    auto notTake = rec(index + 1, nums, answer); // not take
    result.insert(result.end(), notTake.begin(), notTake.end());
    return result;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> ans;
    return rec(0, nums, ans);
}

long long main()
{
    return 0;
}