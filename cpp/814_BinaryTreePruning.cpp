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
    TreeNode* pruneTree(TreeNode* root) {
        return func1(root);
    }

    TreeNode* func1(TreeNode* root) {
        if (root == NULL) {
        	return NULL;
        }

        TreeNode* lf = func1(root->left);
        TreeNode* rt = func1(root->right);

        if (lf == NULL && rt == NULL) {
        	if (root->val == 1) {
        		root->left = NULL;
        		root->right = NULL;
        		return root;
        	} else {
        		return NULL;
        	}
        } else {
        	root->left = lf;
        	root->right = rt;
        	return root;
        }
    }
};
