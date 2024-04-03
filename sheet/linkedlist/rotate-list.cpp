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


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

/*

Consider a linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 2 (rotate by 2 to the right):

Base cases are not met, so continue.
The length calculation is skipped in this approach.
k is adjusted to k % length = 2 % 5 = 2.
We iterate k = 2 times:
current moves to nodes 2 and 3.
Since current->next (node 4) is not NULL, prev remains NULL.
After the loop, current points to node 3 (the new head).
prev is still NULL, so no circular connection was created. We set current->next (node 4's next) to NULL to break the link, and return current (node 3) as the new head.
The resulting linked list will be 3 -> 4 -> 5 -> 1 -> 2.
*/


using namespace std;
    //Time Complexity: o(N) + o(N - (N % k)) = O(N)
    //Space Complexity : o(1)



ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        ListNode* current = head;
        int length = 1;
        while (current->next != NULL)
        {       
            length++;
            current = current->next;
        }

        current->next = head;
        
        k = k % length;

        k = length - k;
        while (k--)
        {
            current = current->next;
        }

        head = current->next;
        current->next = NULL;
        
        return head;
        
    }

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}