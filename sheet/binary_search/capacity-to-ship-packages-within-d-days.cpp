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
//Time Complexity: o(N * log(max))
//Space Complexity : o(1)


int numOfDays(vector<int>& weights, int cap){
    
    int days = 1;
    int currentLoad = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if(currentLoad + weights[i] > cap){
            days += 1;
            currentLoad = weights[i];
        }
        else{
            currentLoad += weights[i];
        }
    }
    return days;
    
}

//answer in max element and sum of arr
  int shipWithinDays(vector<int>& weights, int days) {
        int mini = INT_MIN;
        int maxi = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            mini = max(weights[i], mini);
            maxi += weights[i];
        }
        while (mini <= maxi)
        {
            int mid = (maxi + mini)/ 2;
            if(numOfDays(weights, mid) <= days ){
                   
                     maxi = mid - 1;

            }else   if(numOfDays(weights, mid) > days ){
                mini  = mid + 1;
            }
            
        }
        
        return mini;
        
    }

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}