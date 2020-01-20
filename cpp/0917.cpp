class Solution {
public:
  string reverseOnlyLetters(string S) {
    int i = 0;
    int j = S.length() - 1;
    while (i < j) {
      while (!isalpha(S[i]) && i < j) {
        i++;
      }
      while (!isalpha(S[j]) && j > i) {
        j--;
      }
      if (i < j) {
        char c = S[i];
        S[i] = S[j];
        S[j] = c;
        i++;
        j--;
      }
    }

    return S;
  }
};