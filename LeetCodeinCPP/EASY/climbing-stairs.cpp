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

/*

Try to represent a problem in terms of index

Do all possible stuffs on that index according to problem

Sum of all Stuff: count all way

Min of all: Min of all

*/


using namespace std;

   int climbStairs(int n) {
        //return 1 to count all ways
        if (n <= 1) return 1;
        int dp[3];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[2] = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}