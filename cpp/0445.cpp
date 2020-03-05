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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // return func1(l1, l2);
    return func2(l1, l2);
  }

  ListNode* func1(ListNode* l1, ListNode* l2) {
    // l1 = listReverse(l1);
    // l2 = listReverse(l2);
    l1 = listNonRecursiveReverse(l1);
    l2 = listNonRecursiveReverse(l2);

    ListNode* head = NULL;
    ListNode* curr = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry > 0) {
      int val = carry;
      if (l1) {
        val += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        val += l2->val;
        l2 = l2->next;
      }
      carry = val / 10;

      if (curr == NULL) {
        curr = new ListNode(val % 10);
        head = curr;
      } else {
        curr->next = new ListNode(val % 10);
        curr = curr->next;
      }
    }

    return listReverse(head);
  }

  // stack, 2020-03-05
  ListNode* func2(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
      return l2;
    }
    if (l2 == NULL) {
      return l1;
    }

    stack<ListNode*> stk1;
    stack<ListNode*> stk2;

    while (l1 != NULL) {
      stk1.push(l1);
      l1 = l1->next;
    }
    while (l2 != NULL) {
      stk2.push(l2);
      l2 = l2->next;
    }

    ListNode *head = NULL;
    ListNode *curr = NULL;
    int carry = 0;

    while (!stk1.empty() || !stk2.empty()) {
      int sum = carry;
      if (!stk1.empty()) {
        sum += stk1.top()->val;
        stk1.pop();
      }
      if (!stk2.empty()) {
        sum += stk2.top()->val;
        stk2.pop();
      }
      curr = new ListNode(sum%10);
      carry = sum / 10;

      if (head == NULL) {
        head = curr;
      } else {
        curr->next = head;
        head = curr;
      }
    }
    if (carry > 0) {
      curr = new ListNode(carry);
      curr->next = head;
      head = curr;
    }

    return head;
  }

private:
  // ** recursive
  ListNode* listReverse(ListNode* node) {
    if (node == NULL || node->next == NULL) {
      return node;
    }
    ListNode* second = node->next;
    ListNode* newHead = listReverse(second);
    second->next = node;
    node->next = NULL;
    return newHead;
  }
  // ** non-recursive
  ListNode* listNonRecursiveReverse(ListNode* node) {
    if (node == NULL) {
      return NULL;
    }

    vector<ListNode*> vec;
    while (node != NULL) {
      vec.push_back(node);
      node = node->next;
    }

    for (int i = vec.size() - 1; i > 0; i--) {
      vec[i]->next = vec[i-1];
    }
    vec[0]->next = NULL;

    return vec[vec.size() - 1];
  }
};

