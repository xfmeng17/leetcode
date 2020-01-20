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
  TreeNode *insertIntoBST(TreeNode *root, int val) { return func1(root, val); }

  TreeNode *func1(TreeNode *root, int val) {
    if (root == NULL) {
      return new TreeNode(val);
    }
    if (root->val > val) {
      root->left = func1(root->left, val);
    }
    if (root->val < val) {
      root->right = func1(root->right, val);
    }

    return root;
  }
};
