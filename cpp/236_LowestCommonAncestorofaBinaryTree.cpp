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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func1(root, p, q);
    }

    TreeNode* func1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_anc;
        vector<TreeNode*> q_anc;
        findAncestor(root, p, p_anc);
        findAncestor(root, q, q_anc);
        
        int p_size = p_anc.size();
        int q_size = q_anc.size();
        int size = min(p_size, q_size);
        TreeNode* ancestor = NULL;
        for (int i = 0; i < size; i++) {
            if (p_anc[i] == q_anc[i]) {
                ancestor = p_anc[i];
            } else {
                break;
            }
        }
        return ancestor;
    }
    bool findAncestor(TreeNode* root, TreeNode* node, vector<TreeNode*>& ancestor) {
        if (root == NULL) {
            return false;
        }

        ancestor.emplace_back(root);
        if (root == node) {
            return true;
        }

        if (findAncestor(root->left, node, ancestor)) {
            return true;
        }
        if (findAncestor(root->right, node, ancestor)) {
            return true;
        }

        ancestor.pop_back();
        return false;
    }
};