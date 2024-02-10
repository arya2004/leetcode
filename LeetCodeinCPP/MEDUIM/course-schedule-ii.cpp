#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
//topological sort
vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        const int rr = numCourses;
        int m = prerequisites.size();
        vector<vector<int>> adjacent(rr);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adjacent[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto i: adjacent[i])
            {
                indegree[i]++;
            }
            
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto i: adjacent[node])
            {
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        

        if(topo.size() == numCourses){
            return topo;
        }
        return {};
        
        
        
    }
int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}