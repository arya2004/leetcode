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
//hardcode
int f(int ind, vector<int> &nums, vector<int> &dp){
    if(ind == 0) return nums[0];
    if(ind < 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int pick  = nums[ind] + f(ind - 2, nums, dp);
    int notPick = 0 + f(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}


  int rob_memonization(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
 //tc o(n)
 //sc o(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if(i > 1) take += prev2;
            int notTake = 0 + prev;

            int curi = max(take, notTake);

            prev2 = prev;
            prev = curi;
        }
        return prev;
        
    }
    
int main()
{
    return 0;
}