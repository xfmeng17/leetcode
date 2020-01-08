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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        queue<TreeNode*> node_q;
        queue<int> level_q;

        node_q.push(root);
        level_q.push(0);
        ret.emplace_back(root->val);

        while (!node_q.empty()) {
            TreeNode* node = node_q.front();
            int level = level_q.front();

            if (ret.size() <= level) {
                ret.emplace_back(node->val);
            } else {
                ret[level] = node->val;
            }

            node_q.pop();
            level_q.pop();
            if (node->left) {
                node_q.push(node->left);
                level_q.push(level+1);
            }
            if (node->right) {
                node_q.push(node->right);
                level_q.push(level+1);
            }
        }

        return ret;
    }
};