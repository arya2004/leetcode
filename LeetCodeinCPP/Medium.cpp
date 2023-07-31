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



};