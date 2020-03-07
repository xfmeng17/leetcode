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
    ListNode* oddEvenList(ListNode* head) {
        return func1(head);
    }

    ListNode* func1(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* head1 = head;
        ListNode* curr1 = head1;
        ListNode* next1 = NULL;
        ListNode* tail1 = NULL;

        ListNode* head2 = head->next;
        ListNode* curr2 = head2;
        ListNode* next2 = NULL;

        while (curr1 != NULL && curr2 != NULL) {
            next1 = curr2->next;
            next2 = next1 == NULL ? NULL : next1->next;
            curr1->next = next1;
            curr2->next = next2;
            tail1 = curr1;
            curr1 = next1;
            curr2 = next2;
        }
        if (curr2 != NULL) {
            curr2->next = NULL;
        }
        if (curr1 == NULL) {
            tail1->next = head2;
        } else {
            curr1->next = head2;
        }
        

        return head1;
    }
};