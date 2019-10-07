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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // return func1(preorder);
        return func2(preorder);
    }

    // ** iterative
    // ** time O(N^2)
    TreeNode* func1(vector<int>& preorder) {
        if (preorder.size() <= 0) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *prev = root;
            TreeNode *curr = root;
            int direction = 0;
            while (curr != NULL) {
                if (curr->val < preorder[i]) {
                    prev = curr;
                    curr = curr->right;
                    direction = 1;
                } else {
                    prev = curr;
                    curr = curr->left;
                    direction = 0;
                }
            }
            if (direction == 0) {
                prev->left = new TreeNode(preorder[i]);
            } else {
                prev->right = new TreeNode(preorder[i]);
            }
        }

        return root;
    }

    // ** reference from discuss
    // ** use a boundary to separate deal left or right subtree
    // ** time O(N)
    TreeNode* func2(vector<int>& preorder) {
        int i = 0;
        int boundary = 0;
        for (auto n : preorder) {
            boundary = max(boundary, n);
        }
        
        return helper2(preorder, &i, boundary+1);
    }
    TreeNode* helper2(vector<int>& preorder, int* i, int boundary) {
        if (*i >= preorder.size() || preorder[*i] > boundary) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[*i]);
        (*i)++;
        root->left = helper2(preorder, i, root->val);
        root->right = helper2(preorder, i, boundary);

        return root;
    }
};
