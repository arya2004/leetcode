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
// Recursion: TC: 3^n  SC: N
//dp TC: n*m SC: (n * m) + n


//Tabulation:
//TC: n *m + m
// SC: n * m

int rec(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp ){

    if(j < 0 || j >= matrix[0].size()) return 1e8;
    if(i == 0) return matrix[0][j];
    
    if(dp[i][j] != -1) return dp[i][j];

    int up = matrix[i][j] + rec(i - 1, j, matrix, dp);
    int up_left = matrix[i][j] + rec(i - 1, j -1, matrix, dp);
    int up_right = matrix[i][j] + rec(i - 1, j + 1, matrix, dp);


    dp[i][j] =  min(up, min(up_left, up_right));

    return min(up, min(up_left, up_right));

}


int minFallingPathSum_memoization(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int minumum = 1e9;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            minumum = min(minumum, rec( n -1, i, matrix, dp));
        }
        
        return minumum;

    }



int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int minumum = 1e9;

        vector<vector<int>> dp(m, vector<int>(n, 0));


        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = matrix[i][j] + dp[i - 1][ j];

                int up_left = matrix[i][j];
                if(j - 1 >= 0) up_left += dp[i - 1][j -1];
                else up_left += 1e8;
                int up_right = matrix[i][j]; 
                if(j + 1 < n) up_right += dp[i - 1][ j + 1];
                else up_right += 1e8;

                dp[i][j] =  min(up, min(up_left, up_right));

            }
            
        }
        
        



        for (int i = 0; i < n; i++)
        {
            minumum = min(minumum, dp[n -1][i]);
        }
        
        return minumum;

    }




long long main()
{
    return 0;
}