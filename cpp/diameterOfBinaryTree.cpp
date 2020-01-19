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
  int diameterOfBinaryTree(TreeNode *root) {
    // return func1(root);
    return func2(root);
  }

  // hash map
  int func1(TreeNode *root) {
    unordered_map<TreeNode *, int> diameter;
    getDiameter(root, diameter);
    int max = 0;
    preorder(root, diameter, &max);
    return max;
  }

  int getDiameter(TreeNode *root, unordered_map<TreeNode *, int> &diameter) {
    if (root == NULL) {
      return 0;
    }
    unordered_map<TreeNode *, int>::iterator got;
    if ((got = diameter.find(root)) != diameter.end()) {
      return got->second;
    } else {
      int left = getDiameter(root->left, diameter);
      int right = getDiameter(root->right, diameter);
      int curr = max(left, right) + 1;
      diameter.insert(make_pair(root, curr));
      return curr;
    }
  }

  void preorder(TreeNode *root, unordered_map<TreeNode *, int> &diameter,
                int *max) {
    if (root == NULL) {
      return;
    }
    int cnt = 0;
    unordered_map<TreeNode *, int>::iterator got;
    if ((got = diameter.find(root->left)) != diameter.end()) {
      cnt += got->second;
    }
    if ((got = diameter.find(root->right)) != diameter.end()) {
      cnt += got->second;
    }
    if (cnt >= (*max)) {
      *max = cnt;
    }
    preorder(root->left, diameter, max);
    preorder(root->right, diameter, max);
  }

  // recursion
  int func2(TreeNode *root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

  int dfs(TreeNode *root, int &max) {
    if (root == 0)
      return 0;
    int left = dfs(root->left, max);
    int right = dfs(root->right, max);
    max = std::max((left + right), max);
    return std::max(left, right) + 1;
  }
};
