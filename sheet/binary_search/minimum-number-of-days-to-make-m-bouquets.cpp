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
//Time Complexity: o(N * log(max - min +1))
//Space Complexity : o(1)



bool isPossible(vector<int> &arr, int day,  int m, int k){
    int count = 0;
    int number_of_bouquets = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= day){
            count++;
        }else{

            number_of_bouquets += (count / k);
            count = 0;

        }

    }
     number_of_bouquets += (count / k);


     if(number_of_bouquets >=  m){
        return true;
     }
    return false;
 
    
}

int minDays(vector<int>& bloomDay, int m, int k) {
        //not possible
        if(bloomDay.size() < (double)m * (double)k) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;


        int ans = 0;
        while (low <= high)
        {
            int mid = (low + high)/2;

            if(isPossible(bloomDay, mid, m, k)){
               ans = mid;
               high = mid - 1;
            }else{
                    low = mid + 1;
            }
            

        }
        
        return ans;

}

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}