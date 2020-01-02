/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	vector<char> msg;
    	serialize(root, msg);
    	return string(msg.begin(), msg.end());       
    }
    void serialize(TreeNode* root, vector<char>& msg) {
		if (root == NULL) {
			msg.emplace_back('#');
			msg.emplace_back('|');
			return;
		}
		string str = to_string(root->val);
		for (auto s : str) {
			msg.emplace_back(s);
		}
		msg.emplace_back('|');
		serialize(root->left, msg);
		serialize(root->right, msg);
		return;
	}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		int pos = 0;
		return deserialize(data, &pos, data.length());
    }

    TreeNode* deserialize(string data, int *pos, int len) {
    	int lo = *pos;
    	if (lo >= len) {
    		return NULL;
    	}
    	if (data[lo] == '#') {
    		*pos += 1 + 1;
    		return NULL;
    	}

    	int hi = lo;
    	while (data[hi] != '|') {
    		hi++;
    	}
    	int val = stoi(data.substr(lo, hi - lo + 1));
    	TreeNode* root = new TreeNode(val);
    	*pos = hi + 1;
    	root->left = deserialize(data, pos, len);
    	root->right = deserialize(data, pos, len);
    	return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));