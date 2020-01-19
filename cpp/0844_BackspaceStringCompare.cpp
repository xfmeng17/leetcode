class Solution {
public:
  bool backspaceCompare(string S, string T) { return func1(S, T); }

  bool func1(string S, string T) {
    stack<char> qs;
    stack<char> qt;
    for (char s : S) {
      if (s == '#') {
        if (qs.size() > 0) {
          qs.pop();
        }
      } else {
        qs.push(s);
      }
    }
    for (char t : T) {
      if (t == '#') {
        if (qt.size() > 0) {
          qt.pop();
        }
      } else {
        qt.push(t);
      }
    }
    if (qs.size() != qt.size()) {
      return false;
    }
    while (qs.size() > 0) {
      if (qs.top() != qt.top()) {
        return false;
      } else {
        qs.pop();
        qt.pop();
      }
    }
    return true;
  }
};
