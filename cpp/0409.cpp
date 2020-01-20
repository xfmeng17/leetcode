class Solution {
public:
  int longestPalindrome(string s) { return func1(s); }

  int func1(string s) {
    int uc[26] = {0};
    int lc[26] = {0};
    for (char c : s) {
      if (isupper(c)) {
        uc[c - 'A']++;
      }
      if (islower(c)) {
        lc[c - 'a']++;
      }
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
      res += (uc[i] / 2) * 2;
      res += (lc[i] / 2) * 2;
    }
    if (res < s.length()) {
      res += 1;
    }
    return res;
  }
};
