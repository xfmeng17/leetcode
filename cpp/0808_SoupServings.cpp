class Solution {
public:
  double soupServings(int N) {
    // return func1(N);
    return func2(N);
  }

  // ** recursive + memoization
  double func1(int N) {
    if (N > 5000) {
      return 1.0;
    }
    vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1.0));
    return helper1(N, N, memo);
  }

  double helper1(int A, int B, vector<vector<double>> &memo) {
    if (A <= 0 && B <= 0) {
      return 0.5;
    }
    if (A <= 0) {
      return 1.0;
    }
    if (B <= 0) {
      return 0.0;
    }
    if (memo[A][B] >= 0) {
      return memo[A][B];
    }

    memo[A][B] = 0.0;
    memo[A][B] += helper1(A - 100, B - 0, memo);
    memo[A][B] += helper1(A - 75, B - 25, memo);
    memo[A][B] += helper1(A - 50, B - 50, memo);
    memo[A][B] += helper1(A - 25, B - 75, memo);

    return memo[A][B] *= 0.25;
  }

  // ** reference from diss, thanks to lee215
  // ** https://leetcode.com/problems/soup-servings/discuss/121711
  double func2(int N) {
    double memo[200][200];
    return N >= 4800 ? 1.0 : helper2((N + 24) / 25, (N + 24) / 25, memo);
  }
  double helper2(int a, int b, double memo[][200]) {
    if (a <= 0 && b <= 0)
      return 0.5;
    if (a <= 0)
      return 1;
    if (b <= 0)
      return 0;
    if (memo[a][b] > 0)
      return memo[a][b];
    memo[a][b] = 0.0;
    memo[a][b] += helper2(a - 4, b, memo);
    memo[a][b] += helper2(a - 3, b - 1, memo);
    memo[a][b] += helper2(a - 2, b - 2, memo);
    memo[a][b] += helper2(a - 1, b - 3, memo);
    memo[a][b] *= 0.25;
    return memo[a][b];
  }
};
