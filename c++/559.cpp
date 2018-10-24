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
    int maxDepth(Node* root) {
     	// return func1(root);
     	return func2(root); 
    }

    int func1(Node* root) {
    	if (root == NULL) { return 0; }
    	int max = 0;
    	for (Node* child : root->children) {
    		int dep = func1(child);
    		if (dep > max) max = dep;
    	}
    	return 1 + max;
    }
    int func2(Node* root) {
    	int max = 0;
    	queue<tuple<Node*, int>> que;
    	if (root) {
    		que.push(make_tuple(root, 1));
    	}
    	while (que.size()) {
    		tuple<Node*, int>> t = que.front();
    		que.pop();
    		int dep = get<1>(t);
    		if (dep > max) { max = dep; }
    		for (Node* child : get<0>(t)->children) {
    			que.push(make_tuple(child, dep + 1));
    		}
    	}
    	return max;
    }
};