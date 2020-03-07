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
        return func2(head);
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
    }
};