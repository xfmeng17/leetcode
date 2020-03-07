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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // return func1(l1, l2);
    return func2(l1, l2);
  }

  ListNode* func1(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
      return l2;
    }
    if (l2 == NULL) {
      return l1;
    }

    ListNode *head = NULL;
    ListNode *curr = NULL;

    if (l1->val < l2->val) {
      head = l1;
      curr = head;
      l1 = l1->next;
    } else {
      head = l2;
      curr = head;
      l2 = l2->next;
    }

    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1 != NULL) {
      curr->next = l1;
    }
    if (l2 != NULL) {
      curr->next = l2;
    }
    return head;
  }

  // 2020-03-07, recursive
  ListNode* func2(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
      return l2;
    }
    if (l2 == NULL) {
      return l1;
    }
    if (l1->val < l2->val) {
      l1->next = func2(l1->next, l2);
      return l1;
    } else {
      l2->next = func2(l1, l2->next);
      return l2;
    }
    return NULL;
  }
  
};
