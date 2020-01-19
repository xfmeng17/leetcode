class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    // return func1(triangle);
    // return func2(triangle);
    // return func3(triangle);
    // return func4(triangle);
    return func5(triangle);
  }

  // ** recursive
  int func1(vector<vector<int>> &triangle) { return helper1(triangle, 0, 0); }
  int helper1(vector<vector<int>> &triangle, int l, int c) {
    if (l == triangle.size() - 1) {
      return triangle[l][c];
    }

    int curr = triangle[l][c];
    int lf = helper1(triangle, l + 1, c);
    int rt = helper1(triangle, l + 1, c + 1);

    return curr + min(lf, rt);
  }

  // ** recursive + memoization
  int func2(vector<vector<int>> &triangle) {
    int N = triangle.size();
    vector<vector<int>> memo(N, vector<int>(N + 1, 0));
    return helper2(triangle, 0, 0, memo);
  }
  int helper2(vector<vector<int>> &triangle, int l, int c,
              vector<vector<int>> &memo) {

    if (l == triangle.size() - 1) {
      return triangle[l][c];
    }
    if (memo[l][c] != 0) {
      return memo[l][c];
    }

    int curr = triangle[l][c];
    int lf = helper2(triangle, l + 1, c, memo);
    int rt = helper2(triangle, l + 1, c + 1, memo);
    memo[l][c] = curr + min(lf, rt);

    return memo[l][c];
  }

  // ** 2D array dp
  int func3(vector<vector<int>> &triangle) {
    int N = triangle.size();
    if (N <= 0) {
      return 0;
    }
    vector<vector<int>> dp(N, vector<int>(N + 1, 0));

    dp[0][0] = triangle[0][0];

    for (int l = 1; l < N; l++) {
      for (int i = 0; i < l + 1; i++) {
        dp[l][i] = triangle[l][i];
        bool lfAncestor = i - 1 >= 0;
        bool rtAncestor = i <= l - 1;
        if (lfAncestor && rtAncestor) {
          dp[l][i] += min(dp[l - 1][i - 1], dp[l - 1][i]);
        } else if (lfAncestor) {
          dp[l][i] += dp[l - 1][i - 1];
        } else {
          dp[l][i] += dp[l - 1][i];
        }
      }
    }

    int res = dp[N - 1][0];
    for (int i = 0; i < N; i++) {
      res = min(res, dp[N - 1][i]);
    }

    return res;
  }

  // ** basic 2D reduce to 1D according to 0/1 knapsack
  int func4(vector<vector<int>> &triangle) {
    int N = triangle.size();
    if (N <= 0) {
      return 0;
    }
    vector<int> dp(N, 0);

    dp[0] = triangle[0][0];
    for (int l = 1; l < N; l++) {
      for (int i = l; i >= 0; i--) {
        bool lfAncestor = i - 1 >= 0;
        bool rtAncestor = i <= l - 1;
        int anc = 0;
        if (lfAncestor && rtAncestor) {
          anc = min(dp[i - 1], dp[i]);
        } else if (lfAncestor) {
          anc = dp[i - 1];
        } else {
          anc = dp[i];
        }
        dp[i] = triangle[l][i] + anc;
      }
    }

    int res = dp[0];
    for (int i = 0; i < N; i++) {
      res = min(res, dp[i]);
    }

    return res;
  }

  // ** https://github.com/soulmachine/leetcode
  // ** as-short-as-possible
  int func5(vector<vector<int>> &triangle) {
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j < i + 1; ++j) {
        triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
      }
    }
    return triangle[0][0];
  }
};
