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
	TreeNode* increasingBST(TreeNode* root) {
		// return func1(root);
		return func2(root);
	}
    TreeNode* func1(TreeNode* root) {
    	if (root == NULL) {
    		return NULL;
    	}
        vector<TreeNode*> set;
        helper(root, set);
        int size = set.size();
        for (int i = 0; i < size; i++) {
        	set[i]->left = NULL;
        	set[i]->right = (i < size - 1) ? set[i+1] : NULL;
        }
        return set[0];
    }
    void helper(TreeNode* root, vector<TreeNode*>& set) {
    	if (root == NULL) {
    		return;
    	}
    	helper(root->left, set);
    	set.push_back(root);
    	helper(root->right, set);
    }

    TreeNode* func2(TreeNode* root) {
    	if (root == NULL) {
    		return NULL;
    	}

    	root->left = func2(root->left);
    	root->right = func2(root->right);
    	if (root->left) {
    		TreeNode* newRoot = root->left;
    		TreeNode* currNode = root->left;
    		while(currNode->right) {
    			currNode = currNode->right;
    		}
    		currNode->right = root;
  			root->left = NULL;
    		root = newRoot;
    	}

    	return root;
    }
};	