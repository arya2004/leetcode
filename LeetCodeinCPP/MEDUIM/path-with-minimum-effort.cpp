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

 int minimumEffortPath(vector<vector<int>>& heights) {
       // {difference, {x, y}}
       priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0; 
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty())
        {   
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == n-1 && y == m-1)
            {
                return diff;
            }

            for (int i = 0; i < 4; i++)
            {
               int newX = x + dirs[i].first;
               int newY = y + dirs[i].second;

               if(newX >= 0 && newX < n && newY >= 0 && newY < m)
               {
                  int newEffort = max(abs(heights[x][y] - heights[newX][newY]), diff);

                  if(newEffort < dist[newX][newY])
                  {
                     dist[newX][newY] = newEffort;
                     pq.push({newEffort, {newX, newY}});
                  }
               }
            }
            
            
        }
        return -1;
    
    }

int main()
{
    return 0;
}