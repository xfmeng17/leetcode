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
    vector<int> findMode(TreeNode* root) {
    	return func1(root);
    }

    // ** func1 with extra O(n) space
    vector<int> func1(TreeNode* root) {
    	vector<int> res;
		unordered_map<int, int> map;
		int max = 0;
		queue<TreeNode*> q;
		if (root != NULL) {
			q.push(root);
		}
		while (q.size() > 0) {
			TreeNode* node = q.front();
			q.pop();
			map[node->val]++;
			max = max < map[node->val] ? map[node->val] : max;
			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}
		for (auto it = map.begin(); it != map.end(); it++) {
			if (it->second == max) {
				res.push_back(it->first);
			}
		}
		return res;
    }
};
