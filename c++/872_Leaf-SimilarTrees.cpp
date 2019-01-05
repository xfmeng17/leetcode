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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        valueSequence(root1, seq1);
        vector<int> seq2;
        valueSequence(root2, seq2);
        if (seq1.size() != seq2.size()) {
        	return false;
        } else {
        	for (int i = 0; i < seq1.size(); i++) {
        		if (seq1[i] != seq2[i]) {
        			return false;
        		}
        	}
        }
        return true;
   	}

    void valueSequence(TreeNode* root, vector<int> vec) {
    	if (root == NULL) { return; }
    	valueSequence(root->left, vec);
    	if (root->left == NULL && root->right == NULL) {
    		vec.push_back(root->val);
    	}
    	valueSequence(root->right, vec);
    }
};