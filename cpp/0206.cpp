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
  ListNode *reverseList(ListNode *head) { return func1(head); }

  ListNode *func1(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode *second = head->next;
    ListNode *new_head = func1(second);
    second->next = head;
    head->next = NULL;
    return new_head;
  }
};