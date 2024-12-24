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
  int rob(TreeNode *root) {
    int do_rob = 0, do_not = 0;
    helper(root, &do_rob, &do_not);
    return max(do_rob, do_not);
  }

  void helper(TreeNode *root, int *rob_p, int *not_p) {
    if (root == NULL) {
      *rob_p = 0;
      *not_p = 0;
      return;
    }

    int l_rob = 0, l_not = 0;
    int r_rob = 0, r_not = 0;

    helper(root->left, &l_rob, &l_not);
    helper(root->right, &r_rob, &r_not);

    *rob_p = root->val + l_not + r_not;
    *not_p = max(l_rob, l_not) + max(r_rob, r_not);
    return;
  }
};