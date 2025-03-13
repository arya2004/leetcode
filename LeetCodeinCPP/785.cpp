#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colored(n, -1);  

        for (int start = 0; start < n; start++) {
            if (colored[start] != -1) continue; 

            queue<int> q;
            q.push(start);
            colored[start] = 0; 

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (colored[neighbor] == -1) { 
                        colored[neighbor] = 1 - colored[curr];
                        q.push(neighbor);
                    } else if (colored[neighbor] == colored[curr]) {
                        return false; 
                    }
                }
            }
        }

        return true;    
    }
};
