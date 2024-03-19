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
//Time Complexity: >> o(2 ^ n)
//Space Complexity : o(target)

//Memoization
//Time Complexity: >> o(n * target)
//Space Complexity : o(target * n) + o(T)

int rec(int index, int target, vector<int>& coins,  vector<vector<int>>& dp)
{   

    if(index == 0){
        
        if(target % coins[index] == 0) return target / coins[index];
        return 1e9;
    }

    if(dp[index][target] != -1) return dp[index][target];
        

    int notTake = 0 + rec(index - 1, target, coins, dp);
    int take = INT_MAX;
    if(coins[index] <= target) take = 1 + rec( index, target - coins[index], coins, dp);

    dp[index][target] = min(take, notTake);


    return min(take, notTake);

}

//if infinite supply/ multiple use, stay at same index

//if taken, then possible that multiple times taken, so stay on same place 

int coinChange(vector<int>& coins, int amount) {
        
    int n = coins.size();
    
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1 ));
    
    int ans = rec(n -1, amount, coins, dp);
    if(ans >= 1e9) return -1;
    return ans;

}


int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}