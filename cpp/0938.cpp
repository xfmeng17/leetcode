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
  int rangeSumBST(TreeNode *root, int L, int R) {
    // return func1(root, L, R);
    return func2(root, L, R);
  }

  // ** simple
  int func1(TreeNode *root, int L, int R) {
    int res = 0;
    if (root == NULL) {
      return res;
    }

    if (root->val >= L && root->val <= R) {
      res += root->val;
    }
    res += func1(root->left, L, R);
    res += func1(root->right, L, R);

    return res;
  }

  // ** use bst
  int func2(TreeNode *root, int L, int R) {
    int res = 0;
    if (root == NULL) {
      return res;
    }
    if (root->val >= L && root->val <= R) {
      res += root->val;
    }
    if (root->val > L) {
      res += func1(root->left, L, R);
    }
    if (root->val < R) {
      res += func1(root->right, L, R);
    }
    return res;
  }
};
