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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // return func1(head, m, n);
        return func2(head, m, n);
    }

    // One pass with stack
    ListNode* func1(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (m >= n) {
            return head;
        }

        ListNode* tail1 = NULL;
        ListNode* tail2 = NULL;
        ListNode* curr = head;
        stack<ListNode*> stk;
        int sz = 1;

        while (curr != NULL) {
            if (sz == m-1) {
                tail1 = curr;
            }
            if (sz >= m && sz <= n) {
                stk.push(curr);
            }
            curr = curr->next;
            sz++;
        }
        tail2 = stk.top()->next;

        if (tail1 == NULL && tail2 == NULL) {
            return reverseList(head);
        } else if (tail1 == NULL) {
            stk.top()->next = NULL;
            ListNode* new_head = reverseList(head);
            head->next = tail2;
            return new_head;
        } else if (tail2 == NULL) {
            tail1->next = reverseList(tail1->next);
            return head;
        } else {
            stk.top()->next = NULL;
            ListNode* next1 = tail1->next;
            tail1->next = reverseList(tail1->next);
            next1->next = tail2;
            return head;
        }

        return NULL;
    }

    // No need use a extra stack
    ListNode* func2(ListNode* head, int m, int n) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (m >= n) {
            return head;
        }

        ListNode* start = NULL;
        ListNode* start_pre = NULL;
        ListNode* end = NULL;
        ListNode* end_next = NULL;
        ListNode* curr = head;
        int sz = 1;

        while (curr != NULL) {
            if (sz == m-1) {
                start_pre = curr;
            }
            if (sz == m) {
                start = curr;
            }
            if (sz == n) {
                end = curr;
                end_next = end->next;
            }
            curr = curr->next;
            sz += 1;
        }

        // 1. all need reverse, same condition: n-m+1 == sz
        if (start == head && end_next == NULL) {
            return reverseList(head);
        }
        // 2. from head to end
        if (start == head) {
            end->next = NULL;
            curr = reverseList(head);
            head->next = end_next;
            return curr; // or end
        }
        // 3. from start to tail
        if (end_next == NULL) {
            start = reverseList(start);
            start_pre->next = start;
            return head;
        }
        // 4. from start to end
        end->next = NULL;
        curr = reverseList(start);
        start_pre->next = end;
        start->next = end_next;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* second = head->next;
        ListNode* new_head = reverseList(second);
        second->next = head;
        head->next = NULL;

        return new_head;
    }
};