#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        


        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for(auto &m: mpp){
            pq.push(m);
        }

        vector<int> ans;


        for (int i = 0; i < k; i++)
        {   
            pair<int,int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
        }
        

        return ans;
    }
};