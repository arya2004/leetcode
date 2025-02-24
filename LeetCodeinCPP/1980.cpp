#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            int b = nums[0].size();
            string base = "";
            for (int i = 0; i < b; i++)
            {
                base.push_back('0');
            }
            

            return rec(nums, base,0);
        }

        string rec(vector<string>& nums, string toFind, int n){
            if(find(nums.begin(), nums.end(), toFind) == nums.end()){
                return toFind;
            }
            for(int i = n; i < toFind.size(); i++){
                toFind[i] = '1';
                string a = rec(nums, toFind, i + 1);
                if (!a.empty()) return a; 
                toFind[i] = '0';
            }

            return "";

        }
    };