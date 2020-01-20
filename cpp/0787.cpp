class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    return func1(n, flights, src, dst, K);
  }

  int func1(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    int MaxPrice = 10000 * (K + 1) + 1;
    vector<vector<int>> arr(n, vector<int>(n, MaxPrice));
    vector<vector<int>> dp1(n, vector<int>(n, MaxPrice));
    vector<vector<int>> dp2(n, vector<int>(n, MaxPrice));

    for (auto f : flights) {
      arr[f[0]][f[1]] = f[2];
      dp1[f[0]][f[1]] = f[2];
      dp2[f[0]][f[1]] = f[2];
    }
    for (int i = 0; i < n; i++) {
      dp1[i][i] = 0;
      dp2[i][i] = 0;
    }

    int res = dp1[src][dst];

    for (int k = 1; k <= K; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          for (int x = 0; x < n; x++) {
            dp1[i][j] = min(dp1[i][j], (dp2[i][x] + arr[x][j]));
          }
        }
      }
      res = min(res, dp1[src][dst]);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          dp2[i][j] = dp1[i][j];
        }
      }
    }

    return res < MaxPrice ? res : -1;
  }
};
