#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    //bfs mark
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        pair<int,int> temp = q.front();
                        q.pop();
                        int x = temp.first;
                        int y = temp.second;
                        if(x-1 >= 0 && !visited[x-1][y] && grid[x-1][y] == '1'){
                            q.push({x-1, y});
                            visited[x-1][y] = true;
                        }
                        if(x+1 < m && !visited[x+1][y] && grid[x+1][y] == '1'){
                            q.push({x+1, y});
                            visited[x+1][y] = true;
                        }
                        if(y-1 >= 0 && !visited[x][y-1] && grid[x][y-1] == '1'){
                            q.push({x, y-1});
                            visited[x][y-1] = true;
                        }
                        if(y+1 < n && !visited[x][y+1] && grid[x][y+1] == '1'){
                            q.push({x, y+1});
                            visited[x][y+1] = true;
                        }
                        
                    }
                    
                }
            }
            
        }
        


        return count;
    }
};