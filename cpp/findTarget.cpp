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
  bool findTarget(TreeNode *root, int k) {
    // return func1(root, k);
    // return func2(root, k);
    return func3(root, k);
  }

  // basic binary search
  // Time complexity: O(nlog(n))
  // Space complexity: O(h)
  // h is the height of the tree for recursion
  bool func1(TreeNode *root, int k) { return helper(root, root, k); }

  // helper functions
  bool helper(TreeNode *node, TreeNode *root, int k) {
    if (node == NULL) {
      return false;
    }
    int x = k - node->val;
    TreeNode *t = find(root, x);
    if (t && t != node) {
      return true;
    } else {
      return helper(node->left, root, k) || helper(node->right, root, k);
    }
  }
  TreeNode *find(TreeNode *root, int x) {
    if (root == NULL) {
      return NULL;
    }
    if (root->val == x) {
      return root;
    } else if (root->val > x) {
      return find(root->left, x);
    } else {
      return find(root->right, x);
    }
  }

  // convert BST to ordered array and use two pointer way
  // Time complexity: O(n)
  // Space complexity: O(n)
  bool func2(TreeNode *root, int k) {
    vector<int> arr;
    inorder(root, arr);
    int i = 0, j = arr.size() - 1;
    while (i < j) {
      if (arr[i] + arr[j] == k) {
        return true;
      } else if (arr[i] + arr[j] > k) {
        j--;
      } else {
        i++;
      }
    }
    return false;
  }
  void inorder(TreeNode *root, vector<int> &arr) {
    if (root == NULL) {
      return;
    }
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
  }

  // hash table
  // Time complexity: O(n)
  // Space complexity: O(n)
  bool func3(TreeNode *root, int k) {
    unordered_set<int> set;
    return dfs(root, set, k);
  }
  bool dfs(TreeNode *root, unordered_set<int> &set, int k) {
    if (root == NULL) {
      return false;
    }
    if (set.count(k - root->val)) {
      return true;
    }
    set.insert(root->val);
    return dfs(root->left, set, k) || dfs(root->right, set, k);
  }
};
