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
// time eLogV
long long countPaths(long long n, vector<vector<long long>>& roads) {
        
     int mod = 1e9+7;
        vector<vector<pair<int, int>>> graph(n);
        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> distance(n, LONG_MAX);
        vector<int> path(n, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;
        path[0] = 1;
        
        while(!pq.empty()) {
            pair<long long, int> t = pq.top();
            pq.pop();
            
            for(auto &nbr: graph[t.second]) {
                long long vert = nbr.first;
                long long edge = nbr.second;
                
                if(distance[vert] > distance[t.second] + edge) {
                    distance[vert] = distance[t.second] + edge;
                    pq.push({distance[vert], vert});
                    path[vert] = path[t.second] %mod;
                }
                else if(distance[vert] == t.first + edge) {
                    path[vert] += path[t.second];
                    path[vert] %= mod;
                }
            }
        }
        
        return path[n-1];

    }


long long main()
{
    return 0;
}