class Solution {
public:
  bool detectCapitalUse(string word) {
    if (word.length() == 0) {
      return true;
    }
    if (isupper(word[0])) {
      return allLower(word) || allUpper(word);
    }
    if (islower(word[0])) {
      return allLower(word);
    }
    return false;
  }

  // helper functions
  bool allUpper(string s) {
    for (int i = 1; i < s.length(); i++) {
      if (!isupper(s[i])) {
        return false;
      }
    }
    return true;
  }
  bool allLower(string s) {
    for (int i = 1; i < s.length(); i++) {
      if (!islower(s[i])) {
        return false;
      }
    }
    return true;
  }
};