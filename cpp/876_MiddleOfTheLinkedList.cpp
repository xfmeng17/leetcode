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
    ListNode* middleNode(ListNode* head) {
  		int length = 0;
  		ListNode* temp = head;
  		while (temp) {
  			temp = temp->next;
  			length++;
  		}
  		int mid = length / 2;
  		while (mid-- > 0) {
  			head = head->next;
  		}
  		return head;
    }
};