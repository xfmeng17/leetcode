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
        // return func1(l1, l2, 0);
        return func2(l1, l2);
    }

    // ** straight forward recursive solution
    ListNode* func1(ListNode* l1, ListNode* l2, int carry) {
    	ListNode* node = new ListNode(0);

        if (l1 == NULL && l2 == NULL) {
        	if (carry == 0) {
        		return NULL;
        	} else {
        		node->val = carry;
        		return node;
        	}
        } else if (l1 != NULL && l2 == NULL) {
        	node->val = (l1->val + carry) % 10;
        	node->next = func1(l1->next, NULL, (l1->val + carry) / 10);
        	return node;
        } else if (l1 == NULL && l2 != NULL) {
        	node->val = (l2->val + carry) % 10;
        	node->next = func1(NULL, l2->next, (l2->val + carry) / 10);
        	return node;
        } else {
        	node->val = (l1->val + l2->val + carry) % 10;
        	node->next = func1(l1->next, l2->next, (l1->val + l2->val + carry) / 10);
        	return node;
        }
    }

    // ** non-recursion solution
    ListNode* func2(ListNode* l1, ListNode* l2) {
    	ListNode* head = NULL;
    	ListNode* curr = NULL;
    	int carry = 0;

    	while (l1 || l2 || carry > 0) {
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

    	return head;
    }
};

