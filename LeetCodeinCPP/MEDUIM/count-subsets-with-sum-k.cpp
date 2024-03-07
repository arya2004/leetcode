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

//recursion TC:  2*n
// SC: N

//memoization
//TC: n * sum
//SC: n * sum
long long mod = 1000000007;
int rec(int n, int k,vector<int>& arr, vector<vector<int>>& dp ){

    if(k == 0) return 1;
    if(n == 0) return (arr[n] == k);

    if(dp[n][k] != -1) return dp[n][k];

    int notPick = rec(n -1, k, arr,dp);

    int pick = 0;
    if(arr[n] <= k){
        pick = rec(n -1, k - arr[n], arr,dp);
    }

    dp[n][k] = (pick + notPick) % mod;

    return (pick + notPick) % mod;

}


int findWays(vector<int>& arr, int k)
{
	
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1) );
    return rec(n -1, k, arr,dp);
}

    
int main()
{
    return 0;
}