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

//brute force
// min(left(i), right(i)) - height[i]
 int trap1(vector<int>& height) {
        int result = 0;
        int n = height.size();
        int l = 0;
        int r = n -1;
        
        int leftMax = 0;
        int rightMax = 0;
        while (l <= r)
        {
            if(height[l] <= height[r]){
                if(height[l] >= leftMax){
                    leftMax = height[l];
                }else{
                    result += leftMax - height[l];
                }
                l++;
            }else{
                if(height[r] >= rightMax){
                    rightMax = height[r];
                }else{
                    result += rightMax - height[r];
                }
                r--;
            
            }
        }
        return result;
    }

     int trap(vector<int>& height) {
        vector<int> prefix(height.size(), 0);
        vector<int> suffix(height.size(), 0);
        int n = height.size();
        int tempPreMax = 0;
        int tempSufMax = 0;
        for (int i = 0; i < n; i++)
        {
            if(height[i] > tempPreMax){
                tempPreMax = height[i];
            }
            prefix[i] = tempPreMax;
        }
        for (int i = n - 1; i >=  0; i--)
        {
            if(height[i] > tempSufMax){
                tempSufMax = height[i];
            }
            suffix[i] = tempSufMax;
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result += min(prefix[i], suffix[i]) - height[i];
        }

        return result;
        
        
        
    }
int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}