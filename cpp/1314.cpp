class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K) {
    int M = mat.size();
    int N = mat[0].size();
    vector<vector<int>> ret(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        for (int r = max(0, i - K); r <= min(M - 1, i + K); r++) {
          for (int c = max(0, j - K); c <= min(N - 1, j + K); c++) {
            ret[i][j] += mat[r][c];
          }
        }
      }
    }

    return ret;
  }
};