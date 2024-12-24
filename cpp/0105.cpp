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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return func1(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1);
  }
  TreeNode *func1(vector<int> &preorder, int p_lo, int p_hi,
                  vector<int> &inorder, int i_lo, int i_hi) {
    if (p_hi - p_lo < 0) {
      return NULL;
    }
    if (p_hi - p_lo == 0) {
      TreeNode *root = new TreeNode(preorder[p_lo]);
      return root;
    }
    if (p_hi - p_lo == 1) {
      TreeNode *root = new TreeNode(preorder[p_lo]);
      if (preorder[p_lo] == inorder[i_lo]) {
        root->right = new TreeNode(preorder[p_lo + 1]);
      } else {
        root->left = new TreeNode(preorder[p_lo + 1]);
      }
      return root;
    }
    if (p_hi - p_lo == 2) {
      TreeNode *root = new TreeNode(preorder[p_lo]);
      root->left = new TreeNode(preorder[p_lo + 1]);
      root->right = new TreeNode(preorder[p_lo + 2]);
    }

    TreeNode *root = new TreeNode(preorder[p_lo]);
    int i_mid = -1;
    for (int i = i_lo; i <= i_hi; i++) {
      if (inorder[i] == preorder[p_lo]) {
        i_mid = i;
      }
    }
    int left_size = i_mid - i_lo;
    int right_size = i_hi - i_mid;
    root->left = func1(preorder, p_lo + 1, p_lo + 1 + left_size - 1, inorder,
                       i_lo, i_mid - 1);
    root->right =
        func1(preorder, p_lo + 1 + left_size, p_hi, inorder, i_mid + 1, i_hi);

    return root;
  }
};