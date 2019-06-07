class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        return func1(pushed, popped);
    }

    bool func1(vector<int>& pushed, vector<int>& popped) {
    	int N = pushed.size();
    	stack<int> stk;
    	int i = 0, j = 0;
    	while (i < N && j < N) {
    		if (pushed[i] == popped[j]) {
    			i++;
    			j++;
    		} else {
    			if (!stk.empty() && stk.top() == popped[j]) {
    				stk.pop();
    				j++;
    			} else {
    				stk.push(pushed[i]);
    				i++;
    			}
    		}
    	}

    	while (!stk.empty() && j < N) {
    		if (stk.top() != popped[j]) {
    			break;
    		} else {
    			stk.pop();
    			j++;
    		}
    	}

    	return j == N;
    }
};
