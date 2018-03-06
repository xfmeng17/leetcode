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
        // return func1(root);
        return func2(root);
    }

    // two traverses
    // inOrder sumTree() get sum
    // preOrder() add to val
    TreeNode* func1(TreeNode* root) {
        int sum = sumTree(root);
        preOrder(root, &sum);
        return root;
    }
    int sumTree(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return root->val + sumTree(root->left) + sumTree(root->right);
    }
    void preOrder(TreeNode* root, int* sum) {
		if (root == NULL) {
			return;
		}
		preOrder(root->left, sum);
		(*sum) -= root->val;
		root->val += (*sum);
		preOrder(root->right, sum);
    }

    // ref: one traverse by postOrder
	TreeNode* func2(TreeNode* root) {
		int sum = 0;
		postOrder(root, &sum);
		return root;
	}
	void postOrder(TreeNode* root, int* sum) {
		if (root == NULL) {
			return;
		}
		postOrder(root->right, sum);
		(*sum) += root->val;
		root->val = (*sum);
		postOrder(root->left, sum);
	}
};
