class Solution {
public:
    int scoreOfParentheses(string S) {
        return func1(S);
    }
    
    int func1(string S) {
        int res = 0;
        stack<char> stk;
        for (int i = 0; i < S.length(); i++) {
            if (stk.empty()) {
                stk.push(S[i]);
            } else if (stk.top() == '(' && S[i] == ')') {
                res += pow(2, stk.size() - 1);
                int j = i;
                while (!stk.empty() && j < S.length()) {
                    if (stk.top() == '(' && S[j] == ')') {
                        stk.pop();
                        j++;
                    } else {
                        break;
                    }
                }
                if (j > i) {
                    i = j - 1;
                }
            } else {
                stk.push(S[i]);
            }
        }
        return res;
    }
};
