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
    //Time Complexity: o(N^3)
    //Space Complexity : o(1) + response space

 vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> response;
        //sort
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < n; j++)
            {
                if(j !=  i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                      vector<int> temp;
                      temp.push_back(nums[i]) ;  
                      temp.push_back(nums[j]) ;  
                      temp.push_back(nums[k]) ;  
                      temp.push_back(nums[l]) ;    
                      response.push_back(temp);
                      temp.clear();
                      temp.shrink_to_fit();

                      k++;
                      l--;

                        while (k < l && nums[k] == nums[k - 1]) k ++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                     
                        
                        

                    }
                    else if(sum < target) k ++;
                    else l--;
                }
                
            }
            
        }
        return response;

    }

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}