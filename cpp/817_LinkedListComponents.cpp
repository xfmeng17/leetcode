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
    int numComponents(ListNode* head, vector<int>& G) {
        // return func1(head, G);
        return func2(head,G);
    }
	
	// ** straight forward, need O(N) extra space    
    int func1(ListNode* head, vector<int>& G) {
    	unordered_set<int> set;
    	for (int g : G) {
    		set.insert(g);
    	}
    	bool linking = false;
    	int res = 0;

    	while (head != NULL) {
    		if (set.count(head->val) <= 0) {
    			linking = false;
    		} else {
    			if (linking) {
    				// ** nothing
    			} else {
    				linking = true;
    				res++;
    			}
    		}
    		head = head->next;
    	}

    	return res;
    }

    // ** referance, more concise
    int func2(ListNode* head, vector<int>& G) {
    	unordered_set<int> setG(G.begin(), G.end());
    	int res = 0;
    	while (head != NULL) {
    		if (setG.count(head->val) && 
    			(head->next == NULL || setG.count(head->next->val) <= 0)) {
    			res++;
    		}
    		head = head->next;
    	}
    	return res;
    }
};
