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
    void reorderList(ListNode* head) {
        return func1(head);
    }

    void func1(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }

        int size = 0;
        ListNode* curr = NULL;
        ListNode* last = NULL;
        ListNode* head1 = head;
        ListNode* head2 = NULL;

        // 1. Separate head1, head2
        curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }
        int half = size / 2;
        if (size % 2 == 1) {
            half += 1;
        }
        curr = head;
        last = head;
        while (half-- > 0) {
            last = curr;
            curr = curr->next;
        }
        head2 = curr;
        last->next = NULL;
        
        // 2. Reverse head2
        head2 = reverseList(head2);

        // 3. Intersect
        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        ListNode* next1 = NULL;
        ListNode* next2 = NULL;
        while (curr1 != NULL && curr2 != NULL) {
            next1 = curr1->next;
            next2 = curr2->next;
            curr2->next = next1;
            curr1->next = curr2;
            curr1 = next1;
            curr2 = next2;
        }
        // 4. cornar case
        if (curr1)
        return;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* next = head->next;
        ListNode* new_head = reverseList(next);
        next->next = head;
        head->next = NULL;
        return new_head;
    }
};