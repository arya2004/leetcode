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

class Easy {

    vector<int> ans;
  
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

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -1;
        int mid = (low + high) / 2;
        while (low <= high)
        {   
            mid = (low + high) / 2;
            if (nums.at(mid) == target)
            {
                return  mid;
            }
            else if (nums.at(mid) < target)
            {
                low = mid + 1;
            }
            else  
            {
                high = mid -1;
               
            }
        }
        return -1;
    }

    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;
        if (target < nums.at(0)) return 0;
        if (target > nums.at(high)) return high + 1;
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (nums.at(mid) < target)
            {

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
        
    //time : o(nodes)
    //space: o(nodes)
    vector<int> preorderTraversal(TreeNode* root) {
        if (root)
        {
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if (root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            ans.push_back(root->val);
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root)
        {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
        }
        return ans;
    }

    int height = 0;
    //time : o(nodes)
    //space: o(nodes)
    int maxDepth(TreeNode* root) {
        if (root)
        {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
        return height;
    }

    int helperIsBalanced(TreeNode* root) {
        if (root == NULL) return 0;
        
            return 1 + max(helperIsBalanced(root->left), helperIsBalanced(root->right));
    
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;

        int left = helperIsBalanced(root->left);
        int right = helperIsBalanced(root->right);

        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    //time : o(nodes)
    //space: o(nodes)  
    int maxi = 0;
    int _diameterOfBinaryTree(TreeNode* root)
    {   
        if (root == NULL) return 0;

        int lh = _diameterOfBinaryTree(root->left);
        int rh = _diameterOfBinaryTree(root->right);
        maxi = max(maxi, lh + rh);

        return 1 + max(lh, rh);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        _diameterOfBinaryTree(root);
        return maxi;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
        {
            return p == q;
        }
        bool current = p->val == q->val;
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        return current && l && r;

    }

    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;


        while (root != NULL && root->val != val)
        {

            if (root->val > val)
            {
                root = root->left;
            }
            else if (root->val < val)
            {
                root = root->right;
            }

        }
        return root;

    }



    bool evaluateTree(TreeNode* root) {
        if (root == NULL) return NULL;

        int sign = root->val;
        bool a = evaluateTree(root->left);
        bool b = evaluateTree(root->right);
        if (sign == 2)
        {
            return (a || b);
        }
        else if (sign == 3)
        {
            return (a && b);
        }
        return root->val;
    }
};