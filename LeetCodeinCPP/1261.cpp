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


class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        s.insert(0);
        rec(root);
    }
    
    bool find(int target) {
        return s.find(target) != s.end();
    }

private:
    set<int> s;

    void rec(TreeNode* root){
        if(root == NULL){
            return;
        }
        if(root->left != NULL){
            root->left->val = 2 * root->val + 1; 
            s.insert(root->left->val);
            rec(root->left);
        }
            
        
        if(root->right != NULL){
            root->right->val = 2 * root->val + 2;
            s.insert(root->right->val);
            rec(root->right);
        }
            


    }

};
    