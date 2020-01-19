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
  void flatten(TreeNode *root) { func1(root); }

  //** in palce, T(n) = 2T(n) + n/2 => O(nlgn)
  void func1(TreeNode *root) { root = helper1(root); }
  TreeNode *helper1(TreeNode *root) {
    if (root == NULL) {
      return NULL;
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (left == NULL && right == NULL) {
      return root;
    }

    TreeNode *newleft = helper1(left);
    TreeNode *newright = helper1(right);
    root->left = NULL;
    root->right = newleft;

    TreeNode *temp = root;
    while (temp->right != NULL) {
      temp = temp->right;
    }
    temp->right = newright;

    return root;
  }
};