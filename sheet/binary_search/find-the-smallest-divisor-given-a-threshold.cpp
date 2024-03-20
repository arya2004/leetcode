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

int sumOfDivisions(vector<int>& nums, int divisor){

    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result += ceil((double)(nums[i]) / (double) (divisor));
    }

    return result;
    
}

int smallestDivisor(vector<int>& nums, int threshold) {

   
    int maxi = INT_MIN;

   

    for (int i = 0; i < nums.size(); i++)
    {
       
        maxi = max(maxi, nums[i]);

    }

    int low = 1;
    int high = maxi;

    while (low <= high)
    {
        int mid = (low + high ) / 2;        

        if(sumOfDivisions(nums, mid) <= threshold){
           
            high = mid - 1;
        }else{
            low = mid + 1;
        }                                                                                      
    }
    return low;
    
} 

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}