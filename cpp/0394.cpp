class Solution {
public:
  string decodeString(string s) { return func1(s); }

  // Stack
  string func1(string s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ']') {
        vector<char> tmp;
        while (stk.top() != '[') {
          tmp.emplace_back(stk.top());
          stk.pop();
        }
        stk.pop(); // pop '['
        int k = 0, q = 1;
        int n = 0;
        while (!stk.empty()) {
          n = stk.top() - '0';
          if (0 > n || n > 9) {
            break;
          }
          k += n * q;
          q *= 10;
          stk.pop(); // pop 'n'
        }
        reverse(tmp.begin(), tmp.end());
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < tmp.size(); j++) {
            stk.push(tmp[j]);
          }
        }
      } else {
        stk.push(s[i]);
      }
    }
    string ret = "";
    while (!stk.empty()) {
      ret += stk.top();
      stk.pop();
    }
    reverse(ret.begin(), ret.end());
    return ret;
  }
};