class Solution {
public:
  int minAddToMakeValid(string S) { return func1(S); }

  int func1(string S) {
    vector<char> stk;
    for (auto s : S) {
      if (stk.empty()) {
        stk.push_back(s);
      } else {
        if (stk.back() == '(' and s == ')') {
          stk.pop_back();
        } else {
          stk.push_back(s);
        }
      }
    }
    return stk.size();
  }
};
