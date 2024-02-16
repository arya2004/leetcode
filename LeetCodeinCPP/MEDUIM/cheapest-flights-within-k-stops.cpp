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

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    for(auto flight : flights){
        adj[flight[0]].push_back({flight[1], flight[2]});
    }
    //stops, src, distance 
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;


    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > k){
            continue;
        }

       for(auto neighbor : adj[node]){
           int newCost = cost + neighbor.second;
           if(newCost < dist[neighbor.first]){
               dist[neighbor.first] = newCost;
               q.push({stops+1, {neighbor.first, newCost}});
           }
       }
        
    }
    {
        /* code */
    }
    



    if(dist[dst] != INT_MAX){
        return dist[dst];
    }
        return -1;
    


    
}

int main()
{
    return 0;
}