class Solution {
public:
  int removePalindromeSub(string s) {
    int N = s.length();
    if (N <= 0) {
      return 0;
    }

    int i = 0;
    int j = 0;
    if (N % 2 == 0) {
      i = N / 2 - 1;
      j = i + 1;
    } else {
      i = N / 2;
      j = i;
    }

    bool check = true;
    for (; i >= 0, j < N; i--, j++) {
      if (s[i] != s[j]) {
        check = false;
        break;
      }
    }

    return check ? 1 : 2;
  }
};