class Solution {
public:
  int integerBreak(int n) { return func1(n); }
  int func1(int n) {
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
      }
    }

    return dp[n];
  }
};
