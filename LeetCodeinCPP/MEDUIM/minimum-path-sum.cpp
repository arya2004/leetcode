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
//dp reduce TC from 2 ^ (m * n) to n*m
//SC (n * m) + path length (m -1 + n -1)


int rec(int m , int n , vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(m == 0 && n == 0) return grid[m][n];
    if(m < 0 || n < 0 ) return 1e9;
    
    if(dp[m][n] != -1) return dp[m][n];


    int up = grid[m][n] + rec(m - 1, n, grid, dp);
    int left = grid[m][n] + rec(m, n - 1, grid, dp);

    dp[m][n] = min(up, left);

    return min(up, left);
}

 int minPathSum_memoization(vector<vector<int>>& grid) {
           int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
           return rec(m -1, n -1, grid,dp);
    }
//Tabulation

 int minPathSum(vector<vector<int>>& grid) {
           int m = grid.size();
            int n = grid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++){

                for (int j = 0; j < n; j++){
   
                    if(i == 0 && j == 0) {
                        dp[i][j] = grid[i][j];
                    }
                    else{
                        int up = grid[i][j];
                        int left = grid[i][j];
                        if( i > 0) up += dp[i -1][j];
                        else up += 1e9;
                        if(j > 0) left = dp[i][j -1];
                        else up += 1e9;
                        dp[i][j] = min(up , left);

                    }
                    
                    
                }
            
         }
         return dp[m - 1][n -1];
    }
long long main()
{
    return 0;
}