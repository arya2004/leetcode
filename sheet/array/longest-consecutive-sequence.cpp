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
    //Time Complexity: o(NlogN)
    //Space Complexity : o(1) 

int _longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lastSmaller = INT_MIN;
        int count = 0;
        int maxCount = 1;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == lastSmaller + 1){
                count++;
                maxCount = max(maxCount, count);
            }else if(nums[i] == lastSmaller){
                continue;
            }else{
                count = 1;
            }
            lastSmaller = nums[i];
        }
        return maxCount;
    }



//Time Complexity: o(N^3)
//Space Complexity : o(1) + response space

int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxCount = 1;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
        }

        for(auto it : s){
            if(s.find(it - 1) == s.end()){
                int cnt = 1;
                int x = it;
                while (s.find(x + 1) != s.end())
                {
                    x+=1;
                    cnt += 1;
                }
                maxCount = max(maxCount, cnt);
            }

        }
       return maxCount;
    }
int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}