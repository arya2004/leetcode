#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smol;
        vector<int> equal;
        vector<int> bigg;

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == pivot){
                equal.push_back(nums[i]);
            }else if (nums[i] < pivot)
            {
                smol.push_back(nums[i]);
            }else{
                bigg.push_back(nums[i]);
            }
            
        }

        smol.insert(smol.end(), equal.begin(), equal.end());
        smol.insert(smol.end(), bigg.begin(), bigg.end());

        return smol;

        
    }
};