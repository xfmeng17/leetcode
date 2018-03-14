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
	int getMinimumDifference(TreeNode* root) {
		// return func1(root);
		return func2(root);
	}

	// tree traverse
	// Time: O(n*h), h is the height of tree 
	// Extra space: O(1)
    int func1(TreeNode* root) {
    	if (root == NULL) {
    		return 0;
    	}
    	int min = 0;
    	if (root->left) {
    		min = abs(root->val - root->left->val);
    	}
    	if (root->right) {
    		min = abs(root->val - root->right->val);
    	}
    	preorder(root, min);
    	return min;
    }
    void preorder(TreeNode* root, int& min) {
    	if (root == NULL) {
    		return;
    	}
    	TreeNode* pred = findPred(root);
    	if (pred) {
    		min = std::min(abs(root->val - pred->val), min);
    		preorder(root->left, min);
    	}
    	TreeNode* succ = findSucc(root);
    	if (succ) {
    		min = std::min(abs(root->val - succ->val), min);
    		preorder(root->right, min);
    	}
    }
    TreeNode* findPred(TreeNode* root) {
    	if (root == NULL || root->left == NULL) {
    		return NULL;
    	}
    	TreeNode* x = root->left;
    	while (x->right) {
    		x = x->right;
    	}
    	return x;
    }
    TreeNode* findSucc(TreeNode* root) {
    	if (root == NULL || root->right == NULL) {
    		return NULL;
    	}
    	TreeNode* x = root->right;
    	while (x->left) {
    		x = x->left;
    	}
    	return x;
    }

    // transform tree to sorted array
    // Time: O(n)
    // Extra space: O(n)
    int func2(TreeNode* root) {
    	vector<int> arr;
    	transform(root, arr);
    	if (arr.size() < 2) {
    		return 0;
    	}
    	int min = arr[1] - arr[0];
    	for (int i = 2; i < arr.size(); i++) {
    		min = std::min((arr[i] - arr[i - 1]) , min);
    	}
    	return min;
    }
    void transform(TreeNode* root, vector<int>& arr) {
    	if (root == NULL) {
    		return;
    	}
		transform(root->left, arr);
    	arr.push_back(root->val);
		transform(root->right, arr);
    }
};
