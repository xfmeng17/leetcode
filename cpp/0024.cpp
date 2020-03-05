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
    ListNode* swapPairs(ListNode* head) {
  		return func1(head);      
    }

    ListNode* func1(ListNode* head) {
    	if (head == NULL || head->next == NULL) {
    		return head;
    	}

    	ListNode *head0 = head;
    	ListNode *curr0 = head0;
    	ListNode *head1 = head->next;
    	ListNode *curr1 = head1;
    	ListNode *curr = head->next->next;
    	int cnt = 2;
    	while (curr != NULL) {
    		if (cnt % 2 == 0) {
    			curr0->next = curr;
    			curr0 = curr;
    		} else {
    			curr1->next = curr;
    			curr1 = curr;
    		}
    		curr = curr->next;
    		cnt++;
    	}
    	curr0->next = NULL;
    	curr1->next = NULL;

    	head = head1;
    	curr0 = head0;
    	curr1 = head1;
    	cnt = 1;
    	while (curr0 != NULL && curr1 != NULL) {
    		if (cnt % 2 == 0) {
    			curr = curr0->next;
    			curr0->next = curr1;
    			curr0 = curr;
    		} else {
    			curr = curr1->next;
    			curr1->next = curr0;
    			curr1 = curr;
    		}
    		cnt++;
    	}

    	return head;
    }
};