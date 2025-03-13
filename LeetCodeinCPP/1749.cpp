#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix_min = 0;
        int prefix_max = 0;
        int current = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            current += nums[i];
            res = max(res, max(abs(current - prefix_min), abs(current - prefix_max)));
            prefix_min = min(current, prefix_min);
            prefix_max = max(prefix_max, current);

        }
        

        return res;
    }
};