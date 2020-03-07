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
    void deleteNode(ListNode* node) {
        return func1(node);
    }

    void func1(ListNode* node) {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
        return;
    }
};