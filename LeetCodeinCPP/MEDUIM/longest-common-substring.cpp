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



//Tabulation
int lcs(string text1, string text2) {

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
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            
            if(text1[i - 1] == text2[j -1]){
                dp[i][j]=  1 + dp[i-1][j-1];

                ans = max(ans, dp[i][j]);
            }

            //not equal
            else{
       
                dp[i][j] = 0;

            }

          
           


        }
        
    }
    
    return ans;

  
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}