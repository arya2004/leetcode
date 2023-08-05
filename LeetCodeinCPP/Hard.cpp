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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};


using namespace std;


class Hard {
public:
    int maxi = INT_MIN;

    int _maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;

        int leftsum = _maxPathSum(root->left);
        if (leftsum < 0) leftsum = 0;
        int rightSUm = _maxPathSum(root->right);
        if (rightSUm < 0) rightSUm = 0;

        maxi = max(maxi, leftsum + rightSUm + root->val);
        return root->val + max(leftsum, rightSUm);
    }

    int maxPathSum(TreeNode* root) {
        _maxPathSum(root);
        return maxi;
    }


};