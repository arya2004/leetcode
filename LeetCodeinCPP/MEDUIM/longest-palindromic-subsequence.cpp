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

int rec(int i, int j, string &s, string &t,vector<vector<int>> &dp){

    if( i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
        int m = 1 + rec(i-1,j-1,s,t, dp);
        dp[i][j] = m;
        return m;
    }

    //not equal

    int a = rec(i -1, j, s,t,dp);
    int b = rec(i, j-1, s,t,dp);

    dp[i][j] = max(a,b);

    return max(a,b);
}

int longestCommonSubsequence_memoization(string text1, string text2) {

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return rec(n - 1, m - 1, text1, text2, dp);
}

//Tabulation
int longestCommonSubsequence(string text1, string text2) {

    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int j = 0; j <= n; j++)
    {
        dp[j][0] = 0;
    }
    

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            
            if(text1[i - 1] == text2[j -1]){
                dp[i][j]=  1 + dp[i-1][j-1];
            }

            //not equal
            else{
                int a = dp[i -1][j];
                int b = dp[i][ j-1];

                dp[i][j] = max(a,b);

            }

          
           


        }
        
    }
    
    return dp[n][m];

  
}
int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}