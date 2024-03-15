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

//Time Complexity: O(n) + log(max_element)

int rate(int k, vector<int> &piles, int h){
   int hours = 0;
        for(int pile : piles){
            if(hours>h) break;
            int div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;
        }
        return hours;
}

int find_greater(vector<int> &piles){
    int maxi = INT_MIN;
    for(int i = 0; i < piles.size(); i++){
        maxi = max(piles[i], maxi);
    }
    return maxi;
}

//hardcode
  int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = find_greater(piles);
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = low +  (high - low) / 2;
            int total_hours = rate(mid, piles, h);

            if(total_hours <= h){
                ans =  mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }

        }
        return ans;
    }
int main()
{
    return 0;
}