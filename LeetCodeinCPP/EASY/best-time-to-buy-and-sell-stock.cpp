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

//TC: o(n)
//SC: o(1)
using namespace std;

 int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }

        return profit;
        
    }



int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}