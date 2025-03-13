#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses); // Use vector instead of VLA
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0); // Use vector instead of VLA
        for (int i = 0; i < numCourses; i++) {
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0){
                q.push(i);  
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(ans.size() == numCourses) return ans;
        return {};
    }
};
