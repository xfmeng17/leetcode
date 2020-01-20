class Solution {
public:
  bool isSubsequence(string s, string t) {
    // return func1(s, t);
    // return func2(s, t);
    return func3(s, t);
  }

  // ** slow, maybe dp is not a good idea
  bool func1(string s, string t) {
    if (s.length() <= 0) {
      return true;
    }

    vector<int> dp(s.length() + 1, 0);
    int pre = 0;
    for (int i = 0; i < t.length(); i++) {
      for (int j = 0; j < s.length(); j++) {
        pre = dp[j + 1];
        if (s[j] == t[i]) {
          dp[j + 1] = pre + 1;
        } else {
          dp[j + 1] = max(dp[j], dp[j + 1]);
        }
        if (dp[j + 1] == s.length()) {
          return true;
        }
      }
    }

    return false;
  }

  // ** iterative check
  bool func2(string s, string t) {
    int si = 0;
    int ti = 0;

    for (si = 0; si < s.length(); si++) {
      while (ti < t.length() && t[ti] != s[si]) {
        ti++;
      }
      if (ti >= t.length()) {
        return false;
      } else {
        ti++;
      }
    }

    return true;
  }

  // ** reference binary search
  bool func3(string s, string t) {
    vector<vector<int>> set(256);
    for (int i = 0; i < t.length(); i++) {
      set[t[i]].push_back(i);
    }

    int prev = -1;
    for (auto c : s) {
      vector<int> &vec = set[c];
      if (vec.size() <= 0) {
        return false;
      }
      int pos = upperBound(vec, prev);
      if (pos == vec.size()) {
        return false;
      }
      prev = vec[pos];
    }

    return true;
  }

  int upperBound(vector<int> &vec, int target) {
    int lo = 0;
    int hi = vec.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (vec[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    return lo;
  }
};