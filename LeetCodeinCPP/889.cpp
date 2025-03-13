#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        map<int, int> mpp;
        
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            
            for (int i = 0; i < n; i++) {
                mpp[postorder[i]] = i;
            }
    
            return build(0, n - 1, 0, n - 1, preorder, postorder);
        }
    
        TreeNode* build(int i1, int i2, int j1, int j2, vector<int>& preorder, vector<int>& postorder) {
            if (i1 > i2 || j1 > j2) {
                return NULL;
            }
    
            TreeNode* root = new TreeNode(preorder[i1]);
            
            if (i1 != i2) {
                int left = preorder[i1 + 1];
                int mid = mpp[left];
                int leftSize = mid - j1 + 1;
    
                root->left = build(i1 + 1, i1 + leftSize, j1, mid, preorder, postorder);
                root->right = build(i1 + leftSize + 1, i2, mid + 1, j2 - 1, preorder, postorder);
            }
    
            return root;
        }
    };
    