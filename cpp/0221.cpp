class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    // return func1(matrix);
    // return func2(matrix);
    // return func3(matrix);
    return func4(matrix);
  }

  //** 1. recursive
  int func1(vector<vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    int ret = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        ret = max(ret, helper1(matrix, i, j));
      }
    }
    return ret * ret;
  }
  int helper1(vector<vector<char>> &matrix, int i, int j) {
    if (i >= matrix.size() || j >= matrix[i].size()) {
      return 0;
    }
    if (matrix[i][j] == '0') {
      return 0;
    }

    int a = helper1(matrix, i, j + 1);
    int b = helper1(matrix, i + 1, j);
    int c = helper1(matrix, i + 1, j + 1);

    return min(a, min(b, c)) + 1;
  }

  //** 2. recursize + memo
  int func2(vector<vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    int ret = 0;
    vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), -1));
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        ret = max(ret, helper2(matrix, i, j, memo));
      }
    }
    return ret * ret;
  }
  int helper2(vector<vector<char>> &matrix, int i, int j,
              vector<vector<int>> &memo) {
    if (i >= matrix.size() || j >= matrix[i].size()) {
      return 0;
    }
    if (matrix[i][j] == '0') {
      return 0;
    }
    if (memo[i][j] != -1) {
      return memo[i][j];
    }

    int a = helper1(matrix, i, j + 1);
    int b = helper1(matrix, i + 1, j);
    int c = helper1(matrix, i + 1, j + 1);

    memo[i][j] = min(a, min(b, c)) + 1;
    return memo[i][j];
  }

  //** 3. iterative + memo
  int func3(vector<vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    int M = matrix.size();
    int N = matrix[0].size();
    int ret = 0;
    vector<vector<int>> memo(M, vector<int>(N, 0));

    for (int i = M - 1; i >= 0; i--) {
      for (int j = N - 1; j >= 0; j--) {
        if (matrix[i][j] == '0') {
          memo[i][j] = 0;
          ret = max(ret, memo[i][j]);
          continue;
        }
        if (i + 1 >= M || j + 1 >= N) {
          memo[i][j] = 1;
          ret = max(ret, memo[i][j]);
          continue;
        }
        int a = memo[i][j + 1];
        int b = memo[i + 1][j];
        int c = memo[i + 1][j + 1];
        memo[i][j] = min(a, min(b, c)) + 1;
        ret = max(ret, memo[i][j]);
      }
    }

    return ret * ret;
  }

  //** 3. iterative + 2N variables
  int func4(vector<vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    int M = matrix.size();
    int N = matrix[0].size();
    int ret = 0;
    vector<vector<int>> memo(2, vector<int>(N, 0));

    for (int i = M - 1; i >= 0; i--) {
      for (int j = N - 1; j >= 0; j--) {
        if (matrix[i][j] == '0') {
          memo[i % 2][j] = 0;
          ret = max(ret, memo[i % 2][j]);
          continue;
        }
        if (i + 1 >= M || j + 1 >= N) {
          memo[i % 2][j] = 1;
          ret = max(ret, memo[i % 2][j]);
          continue;
        }
        int a = memo[i % 2][j + 1];
        int b = memo[(i + 1) % 2][j];
        int c = memo[(i + 1) % 2][j + 1];
        memo[i % 2][j] = min(a, min(b, c)) + 1;
        ret = max(ret, memo[i % 2][j]);
      }
    }

    return ret * ret;
  }
};