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

int rec(int m, int n,vector<vector<int>> &dp ){
    if(m == 0 && n == 0){
        return 1;
    }
    if(m < 0 || n < 0){
        return 0;
    }
    if(dp[m][n] != -1) return dp[m][n];
    int up = rec(m - 1, n, dp);
    int left = rec(m, n - 1, dp);

    dp[m][n] = up + left;

    return up + left;
}


int uniquePaths_memonization(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n, -1));
        return rec(m - 1, n - 1, dp);

    }


//Tabulation
// m  * N TC and SC
int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n, -1));
       
       for (int i = 0; i < m; i++)
       {
            for (int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) dp[0][0] = 1;
                else{
                    int m = 0; 
                    int n = 0;
                    if(i > 0) m = dp[i -1][j];
                    if(j > 0) n = dp[i][j-1];
                    dp[i][j] = m + n;

                }
            }
            
       }

       return dp[m - 1][n -1];
       

    }

//Tabulation SPACE OPTIMISED
// m  * N TC 
//SC is n
int uniquePaths(int m, int n) {
        vector<int> dp(n , 0);
       
       for (int i = 0; i < m; i++)
       {    
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    int m = 0; 
                    int n = 0;
                    if(i > 0) m = dp[j];
                    if(j > 0) n = temp[j-1];
                    temp[j] = m + n;

                }
            }
            dp = temp;
       }

       return dp[n -1];
       

    }

long long main()
{
    return 0;
}