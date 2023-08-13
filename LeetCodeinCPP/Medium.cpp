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


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};



class Medium {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    };
public:
    double myPow(double x, int n) {

        double ans = 1.0;
        long power = n;
        if (power < 0)
        {
            power = -1 * power;
        }
        while (power > 0)
        {
            if (power % 2 == 1)
            {
                ans = ans * x;
                power = power - 1;
            }
            else
            {
                x *= x;
                power /= 2;
            }
        }
        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;

    }

    //time and space o(n)

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> row;
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
                row.push_back(temp->val);
            }
            ans.push_back(row);
        }
        return ans;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool flag = false;
        if (root = NULL) return ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left ) q.push(temp->left);
                if (temp->right ) q.push(temp->right);
                if (flag)
                {
                    level.insert(level.begin(), temp->val);
                }
                else {
                    level.push_back(temp->val);
                }
            }
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* _root = root;
        while (true)
        {
            if (val < _root->val)
            {
                if (_root->left == NULL)
                {
                    _root->left = new TreeNode(val);
                    break;
                }
                else {
                    _root = _root->left;
                }
            }
            else if (val > _root->val)
            {
                if (_root->right == NULL)
                {
                    _root->right = new TreeNode(val);
                    break;
                }
                else {
                    _root = _root->right;
                }
            }
        }
        return root;
    }

    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int> visitd(isConnected.size(), 0);
        
        for (int i = 0; i < isConnected.size(); i++)
        {   
            
            if (visitd[i] == 0)
            {   
                queue<int> q;
                q.push(i);
                count++;
                while (!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    visitd[temp] = 1;
                    for (int a = 0; a < isConnected[temp].size(); a++)
                    {
                        if (visitd[a] != 1 && isConnected[temp][a] == 1 && a != temp)
                        {   
                            q.push(a);
                            visitd[a] = 1;
                        }
                    }
                }

            }
        }
        return count;
    }

    int orangesRotting(vector<vector<int>>& grid) {

    }

};