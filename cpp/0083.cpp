/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) { return func1(head); }

  ListNode *func1(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr != NULL) {
      next = curr->next;
      if (next == NULL || next->val != curr->val) {
        curr = next;
      } else {
        while (next->next != NULL && next->next->val == curr->val) {
          next = next->next;
        }
        curr->next = next->next;
        curr = curr->next;
      }
    }
    return head;
  }
};