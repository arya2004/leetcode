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

using namespace std;

 ListNode* middleNode(ListNode* head) {
    ListNode* hare = head;
    ListNode* t = head;
    while (hare != NULL && hare->next != NULL)
    {
        t = t->next;
        hare = hare->next->next;
    }
    return t;
           
}


int main()
{
    return 0;
}