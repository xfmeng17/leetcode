/*
// Definition for a Node.
class Node {
public:
    int val;
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
  vector<int> preorder(Node *root) {
    // ** recursion
    // return func1(root);
    // ** stack
    return func2(root);
  }
  vector<int> func1(Node *root) {
    vector<int> res;
    helper(root, res);
    return res;
  }
  void helper(Node *root, vector<int> &res) {
    if (root == NULL)
      return;
    res.push_back(root->val);
    for (Node *child : root->children) {
      helper(child, res);
    }
  }
  vector<int> func2(Node *root) {
    vector<int> res;
    stack<Node *> s;
    if (root == NULL) {
      return res;
    }
    s.push(root);
    while (s.size()) {
      Node *top = s.top();
      s.pop();
      res.push_back(top->val);
      vector<Node *> children = top->children;
      for (int i = children.size() - 1; i >= 0; i--) {
        s.push(children[i]);
      }
    }
    return res;
  }
};