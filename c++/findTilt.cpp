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
	int findTilt(TreeNode* root) {
		return func1(root);
		// return func2(root);
	}
	
	// if not check root after the else in sum
	// then I get a runtime error
	// interesting!
    int func1(TreeNode* root) {
    	unordered_map<TreeNode*, int> map;
    	return dfs(root, map);
    }
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& map) {
    	if (root == NULL) {
    		return 0 ;
    	}
    	int t = abs(sum(root->left, map) - sum(root->right, map));
		return t + dfs(root->left, map) + dfs(root->right, map);
    }
    int sum(TreeNode* root, unordered_map<TreeNode*, int>& map) {
    	if (root == NULL) {
    		return 0;
    	}
		unordered_map<TreeNode*, int>::iterator it = map.find(root);
		
        // accept:
        int ans = 0;
		if (it != map.end()) {
			ans = it->second;
		} else {
			ans = root->val + sum(root->left, map) + sum(root->right, map);
			pair<TreeNode*, int> node = make_pair(root, ans);
			map.insert(node);
		}
		return ans;

        // runtime error:
        // if (it != map.end()) {
        //     return it->second;
        // } else {
        //     int ans = root->val + sum(root->left, map) + sum(root->right, map);
        //     pair<TreeNode*, int> node = make_pair(root, ans);
        //     map.insert(node);
        //     return ans;
        // }
    }

    // ref: postorder
    int func2(TreeNode* root) {
    	if (root == NULL) {
    		return 0;
    	}
    	int ans = 0;
    	postorder(root, ans);
    	return ans;
    }
    int postorder(TreeNode* root, int& acc) {
    	if (root == NULL) {
    		return 0;
    	}
    	int left = postorder(root->left, acc);
    	int right = postorder(root->right, acc);
    	acc += abs(left - right);
    	return root->val + left + right;
    }
};
