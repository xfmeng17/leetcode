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
  int sumEvenGrandparent(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    int ret = 0;
    unordered_map<TreeNode *, TreeNode *> parent_map;
    queue<TreeNode *> treeque;

    treeque.push(root);
    while (!treeque.empty()) {
      TreeNode *node = treeque.front();
      if (node->left) {
        parent_map[node->left] = node;
        treeque.push(node->left);
      }
      if (node->right) {
        parent_map[node->right] = node;
        treeque.push(node->right);
      }
      treeque.pop();
    }

    for (auto it = parent_map.begin(); it != parent_map.end(); it++) {
      if (parent_map.find(it->second) != parent_map.end()) {
        if (parent_map[it->second]->val % 2 == 0) {
          ret += it->first->val;
        }
      }
    }
    return ret;
  }
};