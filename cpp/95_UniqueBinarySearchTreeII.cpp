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
    vector<TreeNode*> generateTrees(int n) {
    	// return func1(1, n);
    	return n > 0 ? func2(1, n) : vector<TreeNode*>();
    }

    vector<TreeNode*> func1(int lo, int hi) {
    	vector<TreeNode*> arr;
    	if (lo > hi) {
    		return arr;
    	}
    	for (int mi = lo; mi <= hi; mi++) {
    		vector<TreeNode*> lf = func1(lo, mi-1);
    		vector<TreeNode*> rt = func1(mi+1, hi);
    		if (lf.size() > 0 && rt.size() > 0) {
    			for (auto left : lf) {
    				for (auto right : rt) {
    					TreeNode* root = new TreeNode(mi);
	    				root->left = left;
	    				root->right = right;
	    				arr.push_back(root);
    				}
    			}
    		} else if (lf.size() > 0) {
    			for (auto left : lf) {
    				TreeNode* root = new TreeNode(mi);
    				root->left = left;
    				arr.push_back(root);
    			}
    		} else if (rt.size() > 0) {
    			for (auto right : rt) {
    				TreeNode* root = new TreeNode(mi);
    				root->right = right;
    				arr.push_back(root);
    			}
    		} else {
    			TreeNode* root = new TreeNode(mi);
    			arr.push_back(root);
    		}
    	}
    	return arr;
    }

    // ** reference, more concise for empty return arr
    // ** but less readable
    vector<TreeNode*> func2(int lo, int hi) {
    	vector<TreeNode*> arr;
    	if (lo > hi) {
    		arr.push_back(NULL);
    		return arr;
    	}

    	for (int mi = lo; mi <= hi; mi++) {
    		vector<TreeNode*> lf = func2(lo, mi-1);
    		vector<TreeNode*> rt = func2(mi+1, hi);
    		for (auto left : lf) {
    			for (auto right : rt) {
    				TreeNode* root = new TreeNode(mi);
    				root->left = left;
    				root->right = right;
    				arr.push_back(root);
    			}
    		}
    	}

    	return arr;
    }
};
