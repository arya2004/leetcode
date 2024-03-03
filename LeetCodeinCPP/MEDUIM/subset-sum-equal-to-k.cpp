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

//Recursion
//TC: 2^n
//SC: n


//Memoization
//TC: n * target
//SC: (n * target ) + (n)


int rec(int index, int target, vector<int> & arr, vector<vector<int>> & dp){

    if(target == 0) return true;
    if(index == 0) return (arr[0] == target);

    if(dp[index][target] != -1) return dp[index][target];

    //not take it
    bool notTake = rec(index -1, target, arr, dp);
    //take it
    bool take = false;
    if( target >= arr[index]){
        take = rec(index -1, target - arr[index], arr, dp);
    }

    dp[index][target] = take | notTake;

    return take | notTake;
}


bool _subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return rec(n -1 , k, arr, dp);
    
}

//Tabulation
// TC: N * target
//SC: n * target
bool subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n ; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;

    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
             //not take it
            bool notTake = dp[index -1][ target];
            //take it
            bool take = false;
            if( target >= arr[index]){
                take = dp[index -1][ target - arr[index]];
            }

            dp[index][target] = take | notTake;

            

        }
        
    }
    
    //position with which callled the recurrece function
    return dp[n- 1][k];
    
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}