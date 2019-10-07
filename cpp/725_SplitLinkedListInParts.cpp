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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        return func1(root, k);
    }

    // ** my straight forward
    vector<ListNode*> func1(ListNode* root, int k) {
    	int len = 0;
    	ListNode* node = root;
    	while (node) {
    		len++;
    		node = node->next;
    	}

    	int quotient = len / k;
    	int remainder = len % k;
    	vector<ListNode*> res;
    	
    	for (int i = 0; i < k; i++) {
    		res.push_back(root);
    		for (int j = 0; j < quotient && root; j++) {
    			node = root;
    			root = root ? root->next : NULL;
    		}
    		if (remainder > 0) {
    			node = root;
    			root = root ? root->next : NULL;
    			remainder--;
    		}
    		if (node) {
    			node->next = NULL;
    		}
    	}

    	return res;
    }
};
