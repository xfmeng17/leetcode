class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    return func3(text1, text2);
  }

  int func3(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    if (m == 0 || n == 0) {
      return 0;
    }

    int ret = 0;
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          memo[i][j] = memo[i - 1][j - 1] + 1;
        } else {
          memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
        }
        ret = max(ret, memo[i][j]);
      }
    }

    return ret;
  }
};