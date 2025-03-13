#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        set<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            st.insert(arr[i]);
        }
        int res = 0;

        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                int prev = arr[i];
                int cur = arr[j];
                int next = cur + prev;
                int len = 2;
                while (st.find(next) != st.end())
                {
                    len++;
                    prev = cur;
                    cur = next;
                    next = prev + cur;
                    res = max(res, len);
                }
                
            }
            
        }
        


        return res;
        
    }
};