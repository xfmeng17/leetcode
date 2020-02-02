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
    const long MOD = 10e9 + 7;

    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, long> map;
        long s = sum(root, map);
        long ret = 0;
        
        for (auto it = map.begin(); it != map.end(); it++) {
            ret = max(ret, it->second * (s - it->second) % MOD);
        }
        
        return (int)ret;
    }
    
    long sum(TreeNode* root, unordered_map<TreeNode*, long>& map) {
        if (root == NULL) {
            return 0;
        }
        if (map.find(root) != map.end()) {
            return map[root];
        }
        
        long left = sum(root->left, map);
        long right = sum(root->right, map);
        map[root] = left + right + root->val;
        return map[root];
    }
};
