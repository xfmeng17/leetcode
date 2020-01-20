/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * 2019-07-09
 * First implement a O(1) time next() with O(n) space
 */
class BSTIterator {
private:
  vector<int> valVec;
  int nextPos;

public:
  BSTIterator(TreeNode *root) {
    valVec.clear();
    storeValToVector(root, valVec);
    nextPos = 0;
  }

  /** @return the next smallest number */
  int next() { return valVec[nextPos++]; }

  /** @return whether we have a next smallest number */
  bool hasNext() { return nextPos < valVec.size(); }

  void storeValToVector(TreeNode *root, vector<int> &valVec) {
    if (root) {
      storeValToVector(root->left, valVec);
      valVec.push_back(root->val);
      storeValToVector(root->right, valVec);
    }
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */