/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
	vector<int> postorder(Node* root) {
		// return func1(root);
		return func2(root);
	}
	// ** simple dfs
    vector<int> func1(Node* root) {  
    	vector<int> res;
    	dfs(root, res);
    	return res;
    }
    void dfs(Node* root, vector<int>& vec) {
    	if (root == NULL) { return; }
		for (Node* child : root->children) {
			dfs(child, vec);
		}
		vec.push_back(root->val);
    }
    // ** no recursion
    vector<int> func2(Node* root) {
    	vector<int> res;
    	stack<Node*> s;
    	s.push(root);
    	while (s.size() > 0) {
    		Node* curr = s.top();
    		s.pop();
    		for (Node* child : curr->children) {
    			s.push(child);
    		}
    		res.push_back(curr->val);
    	}
    	// return reverse(res.begin(), res.end());
    	vector<int> reverse_res(res.size());
    	for (int i = res.size() - 1; i >= 0; i++) {
    		reverse_res.push_back(res[i]);
    	}
    	return reverse_res;
    }
};