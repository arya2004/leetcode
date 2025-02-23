#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        int total_happy = 3 * (pow(2, n - 1));
        if( total_happy > k) return "";

        string res = "";
        string choice = "abc";
        int left = 1;
        int right = total_happy;

        for (int i = 0; i < n; i++)
        {
            int cur = left;
            int partitionSize = (right - left + 1) / choice.size();
            for(char c: choice){
                if(cur <= k && k < cur + partitionSize){
                    
                    res.push_back(c);
                    left = cur;
                    right = cur + partitionSize - 1;
                    choice.erase(choice.find(c), 1);
                    break;
                }
                cur += partitionSize;
            }
        }
        
        return res;
    }
};