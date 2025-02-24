#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < gifts.size(); i++)
        {
            pq.push(gifts[i]);
        }

        for (int i = 0; i < k; i++)
        {
            int top = pq.top();
            pq.pop();
            top = floor(sqrt(top));
            pq.push(top);

        }
        long long sum = 0;
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
        
        
        
    }

    string repeatLimitedString(string s, int repeatLimit) {

        
        map<char, int> counter;
        for (int i = 0; i < s.size(); i++)
        {
            counter[s[i]] += 1;
        }

        priority_queue<pair<char, int>> pq;
        for(auto i: counter){
            pq.push(make_pair(i.first, i.second));
        }

        string res = "";

        while (!pq.empty())
        {
            pair<char, int> temp = pq.top();
            pq.pop();

            int currCount = min(temp.second, repeatLimit);
            res.append(currCount, temp.first);

            if(temp.second - currCount > 0 && !pq.empty()){ 
                if(!pq.empty()){
                    pair<char, int> temp2 = pq.top();
                    pq.pop();

                    res.append(1, temp2.first);
                    pq.push(make_pair(temp2.first, temp2.second - 1));
                }
                pq.push(make_pair(temp.first, temp.second - currCount));
            }

        }

        return res;

    }
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
            }

            res += countSwaps(level);
      
        }

        return res;
    }   

    int countSwaps(vector<int>& arr){
        map<int, int> reverseIndex;
        for(int i = 0; i < arr.size(); ++i) reverseIndex[arr[i]] = i;
        int i = 0, ans = 0;
        for(auto [k,v] : reverseIndex){
            if(v == i) { i++; continue; }
            reverseIndex[arr[i]] = v;
            swap(arr[i], arr[v]);
            ans++; i++;
        }
        return ans;
    }
};