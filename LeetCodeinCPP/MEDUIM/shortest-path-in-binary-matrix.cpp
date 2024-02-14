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

 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        pq.push({1, {0, 0}});
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        while(!pq.empty())
        {
            auto [d, p] = pq.top();
            pq.pop();
            int x = p.first;
            int y = p.second;
            if(x == n-1 && y == n-1) return d;
            for(auto dir : dirs)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && d + 1 < dist[nx][ny])
                {
                    dist[nx][ny] = d + 1;
                    pq.push({d + 1, {nx, ny}});
                }
            }
        }
        return -1;
    }

int main()
{
    return 0;
}