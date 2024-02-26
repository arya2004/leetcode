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

//memonization
int f(int day, int last, vector<vector<int>> & points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if(i != last){
                maxi = max(maxi, points[day][i]);
            }
        }
        
        return maxi;
    }

    if(dp[day][last] != -1){
        return dp[day][last];
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if(task != last){
           int point = points[day][task] +  f(day - 1, task, points, dp);
           maxi = max(maxi, point);
             
        }
    }

    return dp[day][last] = maxi;
    
}

int ninjaTraining_memonization(int n, vector<vector<int>> &points)
{   
    vector<vector<int>> dp(n, vector<int>(4, -1));
    // Write your code here.
    return f(n-1, 3, points, dp);
}

//Tabulation


int ninjaTraining(int n, vector<vector<int>> &points)
{   
    vector<vector<int>> dp(n, vector<int>(4, 0));
    // Write your code here.
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max( points[0][1], points[0][2]));
    
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0; 
            int maxi = 0;

            for (int task = 0; task < 3; task++)
            {
                if(task != last){
                    int point = points[day][task] +  dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
            

      
        }
        
    }
    

    return dp[n-1][3];

}

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}