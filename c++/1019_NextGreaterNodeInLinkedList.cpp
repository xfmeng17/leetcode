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
    vector<int> nextLargerNodes(ListNode* head) {
        // return func1(head);
        return func2(head);
    }
    // ** straight forward O(N^2)
    vector<int> func1(ListNode* head) {
    	vector<int> res;
    	while (head) {
    		int larger = 0;
    		ListNode* next = head->next;
    		while (next) {
    			if (next->val > head->val) {
    				larger = next->val;
    				break;
    			} else {
    				next = next->next;
    			}
    		}
    		res.push_back(larger);
    		head = head->next;
    	}
    	return res;
    }

    vector<int> func2(ListNode* head) {
    	// int N = 0;
    	// ListNode* temp = head;
    	// while (temp) {
    	// 	N++;
    	// 	temp = temp->next;
    	// }
    	// vector<int> res(N, 0);
    	vector<int> res;
    	stack<ListNode*> stk;
    	stack<int> idx;
    	int cnt = 0;

    	while (head) {
    		res.push_back(0);
    		while (!stk.empty() && head->val > stk.top()->val) {
    			res[idx.top()] = head->val;
    			stk.pop();
    			idx.pop();
    		}
    		stk.push(head);
    		idx.push(cnt++);
    		head = head->next;
    	}

    	return res;
    }
};
