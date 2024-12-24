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
  int deepestLeavesSum(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    queue<TreeNode *> node_queue;
    queue<int> deep_queue;

    int deep = 0;
    int sum = 0;
    node_queue.push(root);
    deep_queue.push(deep);

    while (!node_queue.empty()) {
      TreeNode *node = node_queue.front();
      int d = deep_queue.front();
      if (d == deep) {
        sum += node->val;
      } else {
        sum = 0;
        deep = d;
        sum += node->val;
      }
      node_queue.pop();
      deep_queue.pop();
      if (node->left != NULL) {
        node_queue.push(node->left);
        deep_queue.push(d + 1);
      }
      if (node->right != NULL) {
        node_queue.push(node->right);
        deep_queue.push(d + 1);
      }
    }
    return sum;
  }
};