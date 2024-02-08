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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> resultArray;
        if(intervals.size() == 0){
            return resultArray;
        }
        sort(intervals.begin(), intervals.end());

        vector<int> temp = intervals[0];
        for (int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(intervals[i][1], temp[1]);
            }
            else{
                resultArray.push_back(temp);
                temp = intervals[i];
            }
        }
        resultArray.push_back(temp);
        return resultArray;
        
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}