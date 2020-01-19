#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int findTilt(TreeNode *root) {
    return func1(root);
    // return func2(root);
  }

  // I think the code in comment are same
  // but one gets a runtime error
  // interesting!
  int func1(TreeNode *root) {
    unordered_map<TreeNode *, int> map;
    return preorder(root, map);
  }
  int preorder(TreeNode *root, unordered_map<TreeNode *, int> &map) {
    if (root == NULL) {
      return 0;
    }
    int t = abs(sum(root->left, map) - sum(root->right, map));
    return t + preorder(root->left, map) + preorder(root->right, map);
  }
  int sum(TreeNode *root, unordered_map<TreeNode *, int> &map) {
    if (root == NULL) {
      return 0;
    }
    unordered_map<TreeNode *, int>::iterator it = map.find(root);

    /** accept: **/
    int ans = 0;
    if (it != map.end()) {
      ans = it->second;
    } else {
      ans = root->val + sum(root->left, map) + sum(root->right, map);
      pair<TreeNode *, int> node = make_pair(root, ans);
      map.insert(node);
    }
    return ans;

    /** runtime error: **/

    // if (it != map.end()) {
    //     return it->second;
    // } else {
    //     int ans = root->val + sum(root->left, map) + sum(root->right, map);
    //     pair<TreeNode*, int> node = make_pair(root, ans);
    //     map.insert(node);
    //     return ans;
    // }
  }

  // ref: postorder
  int func2(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int ans = 0;
    postorder(root, ans);
    return ans;
  }
  int postorder(TreeNode *root, int &acc) {
    if (root == NULL) {
      return 0;
    }
    int left = postorder(root->left, acc);
    int right = postorder(root->right, acc);
    acc += abs(left - right);
    return root->val + left + right;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

TreeNode *stringToTreeNode(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size()) {
    return nullptr;
  }

  string item;
  stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode *root = new TreeNode(stoi(item));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while (true) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ',')) {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null") {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

int main() {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    int ret = Solution().findTilt(root);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}

// compile use: 'g++ -std=c++14 findTilt.cpp'
// and run './a.out < 563input.txt'
// all the ways get same answer
// it's not my fault
