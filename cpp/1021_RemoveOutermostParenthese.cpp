class Solution {
public:
  string removeOuterParentheses(string S) { return func1(S); }

  string func1(string S) {
    string res = "";
    int head = 0;
    stack<char> stk;
    for (int i = 0; i < S.length(); i++) {
      if (stk.empty()) {
        stk.push(S[i]);
        continue;
      }
      if (S[i] == '(') {
        stk.push(S[i]);
      } else {
        stk.pop();
        if (stk.empty()) {
          if (i - 1 > head + 1) {
            res += S.substr(head + 1, i - head - 1);
          }
          head = i + 1;
        }
      }
    }
    return res;
  }
};
