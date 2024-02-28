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

int rec(int i, int j, vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){

        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;

        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int up = rec(i - 1, j, dp,obstacleGrid);
        int left = rec(i, j - 1, dp,obstacleGrid);


        dp[i][j] = left + up;

        return left + up;
}

 int uniquePathsWithObstacles_(vector<vector<int>>& obstacleGrid) {
             int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, -1));
           return rec(m -1, n -1, dp, obstacleGrid);
    }

    //Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
         for (int i = 0; i < m; i++)
         {
            for (int j = 0; j < n; j++)
            {   
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    if( i > 0) up = dp[i -1][j];
                    if(j > 0) left = dp[i][j -1];
                    dp[i][j] = up + left;

                }
                
                
            }
            
         }
         return dp[m - 1][n -1];
       
    }

long long main()
{
    return 0;
}