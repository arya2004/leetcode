#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});
        }

        while (!pq.empty())
        {
            pair<int, ListNode*> tp = pq.top();
            pq.pop();
            
            if(tp.second->next != NULL)
                pq.push({tp.second->next->val, tp.second->next});
            temp->next = tp.second;
            temp = temp->next;
            
        }
        

        
        

        return dummy->next;
    }
};