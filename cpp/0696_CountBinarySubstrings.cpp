class Solution {
public:
  int countBinarySubstrings(string s) {
    // return func1(s);
    return func2(s);
  }

  // ** straight forward way
  // ** Time(N^2) for sunstring generate and
  // ** Time((n+1)n + n(n-1) + ... + (2 * 1)) / 2 for check consecutive.
  // ** Time Limit Exceeded
  int func1(string s) {
    int res = 0;
    for (int pos = 0; pos < s.length(); pos++) {
      for (int len = 1; len <= s.length() - pos; len++) {
        string sub = s.substr(pos, len);
        if (isConsecutive(sub)) {
          res++;
        }
      }
    }
    return res;
  }

  // ** referance, genious solution
  int func2(string s) {
    int cur = 1, pre = 0, res = 0;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i - 1])
        cur++;
      else {
        res += min(cur, pre);
        pre = cur;
        cur = 1;
      }
    }
    return res + min(cur, pre);
  }

private:
  bool isConsecutive(string s) {
    if (s.length() <= 0 || s.length() % 2 == 1) {
      return false;
    }

    bool has0 = (s[0] == '0' || s[s.length() - 1] == '0');
    bool has1 = (s[0] == '1' || s[s.length() - 1] == '1');
    if (!has0 || !has1) {
      return false;
    }
    int helf = s.length() / 2;
    for (int i = 1; i < helf; i++) {
      if (s[i] != s[i - 1] || s[i + helf] != s[i + helf - 1]) {
        return false;
      }
    }

    return true;
  }
};
