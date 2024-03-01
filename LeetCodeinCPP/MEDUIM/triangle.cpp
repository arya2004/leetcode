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
// TC n * n
//SC n * n
int rec(int i, int j, vector<vector<int>>& triangle, int n,vector<vector<int>>& dp){

    if(i == n -1 ) return triangle[n -1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + rec(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + rec(i + 1, j + 1, triangle, n, dp);

    dp[i][j] = min(down, diagonal);

    return min(down, diagonal);

}


int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));


        return rec(n - 1, n -1, triangle, n, dp);
    }

long long main()
{
    return 0;
}