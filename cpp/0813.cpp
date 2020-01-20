class Solution {
public:
  double largestSumOfAverages(vector<int> &A, int K) {
    // return func1(A, K);
    // return func2(A, K);
    return func3(A, K);
  }

  double func1(vector<int> &A, int K) { return helper1(A, 0, A.size() - 1, K); }

  double helper1(vector<int> &A, int lo, int hi, int K) {
    if (lo > hi) {
      return 0.0;
    }
    if (K == 1) {
      double sum = 0.0;
      for (int i = lo; i <= hi; i++) {
        sum += A[i];
      }
      return sum / (hi - lo + 1.0);
    }
    if (K == (hi - lo + 1)) {
      double sum = 0.0;
      for (int i = lo; i <= hi; i++) {
        sum += A[i];
      }
      return sum;
    }

    double res = 0.0;
    for (int i = lo; i <= hi; i++) {
      double lf = helper1(A, lo, i, 1);
      double rt = helper1(A, i + 1, hi, K - 1);
      res = max(res, lf + rt);
    }

    return res;
  }

  // ** recursive + memoization
  // ** O(K*N^2) time complexity, TLE
  /* Apparently time complexity is not O(KN^2) cause
  func3() is real O(KN^2). But how to calculate func2()'s time?
     I think I need review CLRS some day.
  */
  double func2(vector<int> &A, int K) {
    int N = A.size();
    if (N <= 0 || K <= 0) {
      return 0.0;
    }

    vector<vector<double>> memo(N, vector<double>(N, 0.0));
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        if (j == i) {
          memo[i][j] = A[j];
        } else {
          memo[i][j] = A[j] + memo[i][j - 1];
        }
        // cout<<memo[i][j]<<" ";
      }
      // cout<<endl;
    }

    return helper2(A, 0, N - 1, K, memo);
  }
  double helper2(vector<int> &A, int lo, int hi, int K,
                 vector<vector<double>> &memo) {

    if (lo > hi) {
      return 0.0;
    }
    if (K == 1) {
      return memo[lo][hi] / (hi - lo + 1.0);
    }
    if (K == hi - lo + 1) {
      return memo[lo][hi];
    }

    double res = 0.0;
    for (int mid = lo; mid <= hi; mid++) {
      double lf = helper2(A, lo, mid, 1, memo);
      double rt = helper2(A, mid + 1, hi, K - 1, memo);
      res = max(res, lf + rt);
    }

    return res;
  }

  // ** memo from discuss
  // ** How to change to bottom-up dp?
  double func3(vector<int> &A, int K) {
    int N = A.size();
    vector<vector<double>> memo(N + 1, vector<double>(K + 1, 0.0));
    double curr = 0.0;
    for (int i = 0; i < N; i++) {
      curr += A[i];
      memo[i + 1][1] = curr / (i + 1);
    }
    return helper3(A, N, K, memo);
  }
  double helper3(vector<int> &A, int n, int k, vector<vector<double>> &memo) {
    if (memo[n][k] > 0) {
      return memo[n][k];
    }
    if (n < k) {
      return 0;
    }
    double curr = 0.0;
    for (int i = n - 1; i > 0; i--) {
      curr += A[i];
      double left = helper3(A, i, k - 1, memo);
      memo[n][k] = max(memo[n][k], left + curr / (n - i));
    }

    return memo[n][k];
  }
};
