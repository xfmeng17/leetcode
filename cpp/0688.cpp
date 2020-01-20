class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    // return func1(N, K, r, c);
    // return func2(N, K, r, c);
    return func3(N, K, r, c);
  }

  // ** top-down, recursive, TLE
  double func1(int N, int K, int r, int c) {
    double all = pow(8.0, K);
    int res = helper1(N, K, r, c);
    return (0.0 + res) / all;
  }
  int helper1(int N, int K, int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) {
      return 0;
    }
    if (K == 0) {
      return 1;
    }

    int d1 = helper1(N, K - 1, r - 2, c - 1);
    int d2 = helper1(N, K - 1, r - 1, c - 2);
    int d3 = helper1(N, K - 1, r + 1, c - 2);
    int d4 = helper1(N, K - 1, r + 2, c - 1);
    int d5 = helper1(N, K - 1, r + 2, c + 1);
    int d6 = helper1(N, K - 1, r + 1, c + 2);
    int d7 = helper1(N, K - 1, r - 1, c + 2);
    int d8 = helper1(N, K - 1, r - 2, c + 1);

    return d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
  }

  // ** top-down, recursive + memoization, AC
  // ** time O(KN^2), space O(KN^2)
  double func2(int N, int K, int r, int c) {
    vector<vector<vector<double>>> memo;
    for (int i = 0; i <= K; i++) {
      vector<vector<double>> vec(N, vector<double>(N, -1.0));
      memo.push_back(vec);
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        memo[0][i][j] = 1;
      }
    }

    double res = helper2(N, K, r, c, memo);
    return res;
  }
  double helper2(int N, int K, int r, int c,
                 vector<vector<vector<double>>> &memo) {

    if (r < 0 || r >= N || c < 0 || c >= N) {
      return 0;
    }
    if (K == 0) {
      return 1;
    }
    if (memo[K][r][c] >= 0) {
      return memo[K][r][c];
    }

    double d1 = helper2(N, K - 1, r - 2, c - 1, memo);
    double d2 = helper2(N, K - 1, r - 1, c - 2, memo);
    double d3 = helper2(N, K - 1, r + 1, c - 2, memo);
    double d4 = helper2(N, K - 1, r + 2, c - 1, memo);
    double d5 = helper2(N, K - 1, r + 2, c + 1, memo);
    double d6 = helper2(N, K - 1, r + 1, c + 2, memo);
    double d7 = helper2(N, K - 1, r - 1, c + 2, memo);
    double d8 = helper2(N, K - 1, r - 2, c + 1, memo);
    memo[K][r][c] = (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8) / 8.0;

    return memo[K][r][c];
  }

  // ** bottom-up dp, AC(really fast)
  // ** time O(KN^2), space O(2N^2) => O(N^2)
  // ** reduce space from K to 2
  double func3(int N, int K, int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) {
      return 0.0;
    }
    if (N <= 0) {
      return 0.0;
    }

    vector<vector<double>> dp1(N, vector<double>(N, 1.0));
    vector<vector<double>> dp2(N, vector<double>(N, 1.0));

    for (int k = 1; k <= K; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          dp1[i][j] = 0.0;
          // ** check 8 direction
          if (i - 2 >= 0 && j - 1 >= 0)
            dp1[i][j] += dp2[i - 2][j - 1] / 8.0;
          if (i - 1 >= 0 && j - 2 >= 0)
            dp1[i][j] += dp2[i - 1][j - 2] / 8.0;
          if (i + 1 < N && j - 2 >= 0)
            dp1[i][j] += dp2[i + 1][j - 2] / 8.0;
          if (i + 2 < N && j - 1 >= 0)
            dp1[i][j] += dp2[i + 2][j - 1] / 8.0;
          if (i + 2 < N && j + 1 < N)
            dp1[i][j] += dp2[i + 2][j + 1] / 8.0;
          if (i + 1 < N && j + 2 < N)
            dp1[i][j] += dp2[i + 1][j + 2] / 8.0;
          if (i - 1 >= 0 && j + 2 < N)
            dp1[i][j] += dp2[i - 1][j + 2] / 8.0;
          if (i - 2 >= 0 && j + 1 < N)
            dp1[i][j] += dp2[i - 2][j + 1] / 8.0;
        }
      }
      // ** copy dp1 to dp2
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          dp2[i][j] = dp1[i][j];
        }
      }
    }

    return dp1[r][c];
  }
};
