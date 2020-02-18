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
    bool isValidBST(TreeNode* root) {
        // return func1(root);
        return func2(root);
    }
    
    // Wrong solution: [10,5,15,null,null,6,20]
    bool func1(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left != NULL) {
            if (root->val <= root->left->val) {
                return false;
            }
            if (func1(root->left) == false) {
                return false;
            }
        }
        if (root->right != NULL) {
            if (root->val >= root->right->val) {
                return false;
            }
            if (func1(root->right) == false) {
                return false;
            }
        }
        return true;
    }

    // Complexity: T(n) = 2T(n/2) + O(n) => O(nlogn)
    bool func2(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int left_max = 0, right_min = 0;
        bool ret = true;
        if (root->left) {
            left_max = getLeftMax(root->left);
            ret = ret && root->val > left_max;
        }
        if (root->right) {
            right_min = getRightMin(root->right);
            ret = ret && root->val < right_min;
        }
        if (ret == false) {
            return false;
        }
        return func2(root->left) && func2(root->right);
    }
    int getLeftMax(TreeNode* root) {
        while (root->right) {
            root = root->right;
        }
        return root->val;
    }
    int getRightMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }
};