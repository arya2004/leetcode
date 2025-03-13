#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;
        int n = colors.size();
        int l = 0;
        for (int r = 1; r < n + k -1; r++)
        {
            if(colors[r % n] == colors[(r - 1) % n])
                l = r;
            
            if(r - l + 1 > k)
                l++;

            if (r - l + 1 == k)
                res++;
            
        }
        


        return res;
    }
};