#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            vector<vector<int>> ans;

            int n1 = 0;
            int n2 = 0;
            while (n1 < nums1.size() && n2 < nums2.size())
            {
                if(nums1[n1][0] == nums2[n2][0]){
                    vector<int> t;
                    t.push_back(nums1[n1][0]);
                    t.push_back(nums1[n1][1] + nums2[n2][1]);
                    n1++;
                    n2++;
                    ans.push_back(t);
                }else if (nums1[n1][0] < nums2[n2][0])
                {
                    vector<int> t;
                    t.push_back(nums1[n1][0]);
                    t.push_back(nums1[n1][1]);
                    n1++;
                    ans.push_back(t);
                }else
                {
                    vector<int> t;
                    t.push_back(nums2[n2][0]);
                    t.push_back(nums2[n2][1]);
                    
                    n2++;
                    ans.push_back(t);
                }
            
                
            }

            while(n1 < nums1.size()){
                vector<int> t;
                t.push_back(nums1[n1][0]);
                t.push_back(nums1[n1][1]);
                
                ans.push_back(t);
                n1++;
            }

            while(n2 < nums2.size()){
                vector<int> t;
                t.push_back(nums2[n2][0]);
                t.push_back(nums2[n2][1]);
                
                ans.push_back(t);
                n2++;
            }
            
            


            return ans;
        }
    };