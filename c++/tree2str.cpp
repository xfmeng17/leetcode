/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
        vector<string> queue;
        inorder(t, queue);
        string s;
        for (int i = 0; i < queue.size(); i++) {
        	s.append(queue[i]);
        }
        return s;
    }

    void inorder(TreeNode* t, vector<string>& queue) {
    	if (t == NULL) {
    		return;
    	}
    	queue.push_back(to_string(t->val));
    	if (t->left) {
    		queue.push_back("(");
    		inorder(t->left, queue);
    		queue.push_back(")");
    	}
    	if (t->right) {
    		if (t->left == NULL) {
				queue.push_back("()");
    		}
    		queue.push_back("(");
    		inorder(t->right, queue);
    		queue.push_back(")");
    	}
    	return;
    }
};
