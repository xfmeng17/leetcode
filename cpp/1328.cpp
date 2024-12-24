class Solution {
public:
  string breakPalindrome(string palindrome) {
    int N = palindrome.length();
    if (N == 1) {
      return "";
    }

    int len = N / 2;

    for (int i = 0; i < len; i++) {
      if (palindrome[i] == 'a') {
        continue;
      }
      palindrome[i] = 'a';
      return palindrome;
    }
    palindrome[N - 1] = palindrome[N - 1] == 'z' ? 'a' : palindrome[N - 1] + 1;

    return palindrome;
  }
};