/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    // return func1(root);
    return func2(root);
  }

  // ** recursion
  vector<vector<int>> func1(Node *root) {
    vector<vector<int>> res;
    helper(root, 0, res);
    return res;
  }
  void helper(Node *root, int level, vector<vector<int>> &res) {
    if (root == NULL) {
      return;
    }
    if (res.size() <= level) {
      vector<int> row = {root->val};
      res.push_back(row);
    } else {
      res[level].push_back(root->val);
    }
    for (auto child : root->children) {
      helper(child, level + 1, res);
    }
  }

  // ** queue with pair<Node*, level>
  vector<vector<int>> func2(Node *root) {
    vector<vector<int>> res;
    queue<pair<Node *, int>> queue;
    if (root) {
      queue.push(make_pair(root, 0));
    }
    while (queue.size()) {
      Node *curr = queue.front().first;
      int level = queue.front().second;
      if (res.size() <= level) {
        vector<int> row = {curr->val};
        res.push_back(row);
      } else {
        res[level].push_back(curr->val);
      }
      queue.pop();
      for (auto child : curr->children) {
        queue.push(make_pair(child, level + 1));
      }
    }
    return res;
  }
};