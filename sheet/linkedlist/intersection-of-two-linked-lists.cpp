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

The function getIntersectionNode(ListNode *headA, ListNode *headB) is designed to find the intersection node of two linked lists. The intersection of two linked lists begins at some node at which the two lists merge into one. The function takes two arguments, headA and headB, which are the head nodes of the two linked lists.

The function first checks if either of the linked lists is empty (i.e., headA or headB is NULL). If either is NULL, the function returns NULL because there can't be an intersection if one or both of the lists are empty.

Next, two pointers a and b are initialized to point to the head nodes of the two linked lists. These pointers will traverse the linked lists.

The function then enters a while loop, which continues until the pointers a and b point to the same node. Inside the loop, the function checks if a is NULL. If it is, a is set to point to headB, effectively making it start traversing the second linked list after reaching the end of the first. If a is not NULL, it simply moves to the next node in its current list. The same process is repeated for b, but with the roles of the linked lists reversed.

This mechanism ensures that if there is an intersection, both a and b will eventually reach it, no matter where it is located or what the relative lengths of the linked lists are. If there is no intersection, a and b will both become NULL at the end of their second traversal, causing the loop to end.

Finally, the function returns a (or b, since they are equal when the loop ends). This is either the intersection node or NULL if no intersection exists.

*/


using namespace std;
    //Time Complexity: o(N)
    //Space Complexity : o(1)




  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* a = headA;
        ListNode*b = headB;

        while (a!= b)
        {
            if(a == NULL) a = headB;
            else a = a->next;

            if(b == NULL) b = headA;
            else b = b->next;
        }
        return a;
        
    }

int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}