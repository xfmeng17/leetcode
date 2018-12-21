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
    vector<TreeNode*> allPossibleFBT(int N) {
        return func1(N);
    }	

    vector<TreeNode*> func1(int N) {
    	queue<pair<TreeNode*, TreeNode*>> que;
    	TreeNode root(0);
    	que.push(make_pair(&root, &root));
    	N--;
    	while (!que.empty() && N > 0) {
    		pair<TreeNode*, TreeNode*> curr = que.front();
    		TreeNode lf(0);
    		TreeNode rt(0);
    		curr.first->left = &lf;
    		curr.first->right = &rt;
    		que.push(make_pair(curr.first, &lf));
    		que.push(make_pair(curr.first, &rt));
    		N -= 2;
    		que.pop();
    	}
    	printf("size = %d\n", que.size());

		vector<TreeNode*> ret(que.size());
		while (!que.empty()) {
			pair<TreeNode*, TreeNode*> curr = que.front();
			ret.push_back(curr.first);
			que.pop();
		}

    	// for (auto it = que.begin(); it != que.end(); ++it) {
    	// 	ret.push_back(*it.first);
    	// }

    	return ret;
    }
};
