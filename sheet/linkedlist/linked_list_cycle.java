package sheet.linkedlist;


// 2 pointer approach
// Time complexity: O(n)
// Space complexity: O(1)

  
  class ListNode {
      int val;
      ListNode next;
      ListNode(int x) {
          val = x;
          next = null;
      }
  }
 

public class linked_list_cycle {
    
    public boolean hasCycle(ListNode head) {
        
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast) return true;
        }

        return false;
    }

}
