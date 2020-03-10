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
    ListNode* deleteDuplicates(ListNode* head) {
        // return func1(head);
        // return func2(head);
        return func3(head);
    }

    // O(n) space, 2 pass time
    ListNode* func1(ListNode* head) {
        unordered_map<int, int> map;
        ListNode* curr = head;
        ListNode* tail = NULL;

        while (curr != NULL) {
            map[curr->val]++;
            curr = curr->next;
        }
        while (head != NULL && map[head->val] > 1) {
            head = head->next;
        }
        if (head == NULL) {
            return NULL;
        }

        curr = head->next;
        tail = head;
        while (curr != NULL) {
            if (map[curr->val] > 1) {
                curr = curr->next;
            } else {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            }
        }
        tail->next = NULL;

        return head;
    }
    
    // O(1) space, 1 pass time ?
    ListNode* func2(ListNode* head) {
        // give up -.-
        return NULL;
    }

    // O(1) space, 1 pass time ?
    // 2020-03-10, re-try
    ListNode* func3(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;

        ListNode* tail = dummy_node;
        ListNode* curr = head;
        ListNode* next = NULL;

        bool has_same = false;
        while (curr != NULL) {
            has_same = false;
            next = curr->next;
            while (next != NULL && curr->val == next->val) {
                next = next->next;
            }
            if (curr->next == next) {
                tail->next = curr;
                tail = tail->next;
                curr = next;
            } else {
                curr = next;
                has_same = true;
            }
        }
        // case: 1->1->null
        if (has_same) {
            tail->next = curr;
            tail = tail->next;
        }

        return dummy_node->next;
    }
};