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
//subset-sum-equal-to-k for more detailed

//Tabulation
// TC: N * target
//SC: n * target
 bool canPartition(vector<int>& nums) {

    int resultant_sums = 0 ;
        
       for (auto x : nums)
            resultant_sums +=x;
        
        if(resultant_sums % 2) return false;
        resultant_sums /= 2;
        
        vector<bool> dp(resultant_sums+1,false);
        dp[0]=true;
        for(auto x:nums){
            for(int i=resultant_sums;i>=x;i--){
                dp[i] = dp[i] || dp[i-x] ;
            }
        }
        return dp[resultant_sums];
    
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}