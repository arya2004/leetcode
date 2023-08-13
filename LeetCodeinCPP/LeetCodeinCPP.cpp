// LeetCodeinCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

//#include "Easy.cpp"
#include "Medium.cpp"

using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//    
//};

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int visited[10] = {0};
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto a: adj[node])
        {
            if (!visited[a])
            {
                visited[a] = 1;
                q.push(a);
            }
            
        }
    }

    return ans;
}

int main()
{   
    /*vector<int> a = { 1,2,4,4,5 };
    int b = 55;
    Easy e;
    cout << e.myPow(4.0, 3);*/
    Medium m;
    vector<vector<int>> isConnected = { {1, 0, 0, 1},{0, 1, 1, 0},{0, 1, 1, 1},{1, 0, 1, 1} };
    cout << m.findCircleNum(isConnected);

}

