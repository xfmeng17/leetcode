class Solution {
public:
  int findGoodStrings(int n, string s1, string s2, string evil) {
    return func1(s1, s2, evil);
  }

  int func1(string s1, string s2, string evil) {
    int ret = 0;
    if (s1.find(evil) == string::npos) {
      ret++;
    }
    while (nextString(s1, s2, s1.size() - 1)) {
      if (s1.find(evil) == string::npos) {
        ret++;
      }
      // cout << s1 << endl;
    }
    return ret;
  }

  bool nextString(string &s1, string &s2, int pos) {
    if (pos < 0) {
      return false;
    }
    if (s1 == s2) {
      return false;
    }

    if (s1[pos] < 'z') {
      s1[pos] += 1;
      return true;
    }

    s1[pos] = 'a';
    pos -= 1;

    return nextString(s1, s2, pos);
  }
};