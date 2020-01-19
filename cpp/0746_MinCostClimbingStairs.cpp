class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    // unordered_map<int, int> dp;
    // return min(func1(cost, 0, dp), func1(cost, 1, dp));
    // return func3(cost);
    // return func4(cost);
    // return func5(cost);
    return func6(cost);
  }

  // ** don't store result into dp will cause TLE.
  int func1(vector<int> &cost, int i, unordered_map<int, int> &dp) {
    if (dp[i]) {
      return dp[i];
    }
    if (i >= cost.size()) {
      return 0;
    }
    int one = cost[i] + func1(cost, i + 1, dp);
    int two = cost[i] + func1(cost, i + 2, dp);
    dp[i] = min(one, two);
    return dp[i];
  }
  // ** I think there are another approach let down to top
  int func2() { return 0; }

  /*
   * Update at 2019-01-19, real DP!!
   * !!! Let dp[i] be the minimum cost to reach the i-th stair
   * and PAY i-th stair in order to continue climbing stairs !!!
   * So that, the answer will be
   * min(dp[n-1], dp[n-2]) or dp[n] - cost[n];
   * formula: dp[i] = cost[i] + min(dp[i-1], dp[i-2])
   */
  int func3(vector<int> &cost) {
    int n = cost.size();
    if (n <= 0) {
      return 0;
    }
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
      dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
    }
    return min(dp[n - 2], dp[n - 1]);
  }
  // ** trim space use, only need 2 variable
  int func4(vector<int> &cost) {
    int n = cost.size();
    if (n <= 0) {
      return 0;
    }
    int dp0 = cost[0];
    int dp1 = cost[1];
    int cur = 0;
    for (int i = 2; i < n; i++) {
      cur = cost[i] + min(dp0, dp1);
      dp0 = dp1;
      dp1 = cur;
    }
    return min(dp0, cur);
  }
  /*
   * Recurive top-down, need a memo.
   * memo[0]  means pay the first (0-th) stair and reach top.
   * PayLast0 means pay the (n-1)-th stair and reach top -- solution0.
   * PayLast1 means pay the (n-2)-th stair, go 2 step and reach top --
   * solution1. We pick the lesser between solution0 and solution1.
   */
  int func5(vector<int> &cost) {
    unordered_map<int, int> memo;
    int n = cost.size();
    int payLast0 = helper5(cost, n - 1, memo);
    int payLast1 = helper5(cost, n - 2, memo);
    return min(payLast0, payLast1);
  }
  int helper5(vector<int> &cost, int n, unordered_map<int, int> &memo) {
    if (memo.count(n) > 0)
      return memo[n];
    if (n <= 1)
      return cost[n];
    int memoLast2 = helper5(cost, n - 2, memo);
    int memoLast1 = helper5(cost, n - 1, memo);
    int memoLast0 = cost[n] + min(memoLast2, memoLast1);
    memo[n] = memoLast0;
    return memoLast0;
  }
  /*
   * Mutiple implement to enhance understanding
   */
  int func6(vector<int> &cost) {
    unordered_map<int, int> memo;
    int n = cost.size();
    return helper6(cost, n, memo);
  }
  int helper6(vector<int> &cost, int n, unordered_map<int, int> &memo) {
    if (memo.count(n) > 0) {
      return memo[n];
    }
    if (n <= 1) {
      memo[n] = cost[n];
    } else if (n >= cost.size()) {
      memo[n] = min(helper6(cost, n - 1, memo), helper6(cost, n - 2, memo));
    } else {
      memo[n] =
          min(helper6(cost, n - 1, memo), helper6(cost, n - 2, memo)) + cost[n];
    }
    return memo[n];
  }
};
