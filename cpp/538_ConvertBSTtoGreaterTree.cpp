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
    TreeNode* convertBST(TreeNode* root) {
    	int sum = 0;
    	helper(root, &sum);
    	return root;
    }

    void helper(TreeNode* root, int* sump) {
    	if (root == NULL) {
    		return;
    	}
    	helper(root->right, sump);
    	root->val += *sump;
    	*sump = root->val;
    	helper(root->left, sump);
    	return;
    }
};