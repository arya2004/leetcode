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

 //tc o(n)
 //sc o(1)
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        //not take first
        int fprev = nums[0];
        int fprev2 = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int ftake = nums[i];
            if(i > 1) ftake += fprev2;
            int fnotTake = 0 + fprev;

            int fcuri = max(ftake, fnotTake);

            fprev2 = fprev;
            fprev = fcuri;
        }
        //not take last
        int lprev = nums[1];
        int lprev2 = 0;
        for (int i = 2; i < n; i++)
        {
            int ltake = nums[i];
            if(i > 2) ltake += lprev2;
            int lnotTake = 0 + lprev;

            int lcuri = max(ltake, lnotTake);

            lprev2 = lprev;
            lprev = lcuri;
        }
        return max(lprev, fprev);
        
    }
    
int main()
{
    return 0;
}