/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null;
        ListNode curr = null;
        
        int carry = 0;
        while (l1 != null && l2 != null) {
            ListNode temp = new ListNode((l1.val+l2.val+carry)%10);
            carry = (l1.val+l2.val+carry)/10;
            if (head == null) {
                head = temp;
                curr = temp;
            }
            else {
                curr.next = temp;
                curr = temp;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        
        while (l1 != null) {
            ListNode temp = new ListNode((l1.val+carry)%10);
            carry = (l1.val+carry)/10;
            if (head == null) {
                head = temp;
                curr = temp;
            }
            else {
                curr.next = temp;
                curr = temp;
            }
            l1 = l1.next;
        }
        
        while (l2 != null) {
            ListNode temp = new ListNode((l2.val+carry)%10);
            carry = (l2.val+carry)/10;
            if (head == null) {
                head = temp;
                curr = temp;
            }
            else {
                curr.next = temp;
                curr = temp;
            }
            l2 = l2.next;
        }
        
        if (carry > 0) {
            ListNode temp = new ListNode(carry);
            curr.next = temp;
            curr = temp;
        }
        
        return head;
    }
}
