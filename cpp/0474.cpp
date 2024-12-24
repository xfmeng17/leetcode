class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    // return func1(strs, m, n);
    // return func2(strs, m, n);
    // return func3(strs, m, n);
    return func4(strs, m, n);
  }

  // Recurrence
  // Time 0(len * 2^N), len = max length of strs, N = strs.size()
  int func1(vector<string> &strs, int m, int n) {
    return helper1(strs, 0, m, n);
  }
  int helper1(vector<string> &strs, int idx, int m, int n) {
    if (idx >= strs.size()) {
      return 0;
    }

    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < strs[idx].length(); i++) {
      if (strs[idx][i] == '0')
        cnt0++;
      if (strs[idx][i] == '1')
        cnt1++;
    }

    int notp = helper1(strs, idx + 1, m, n);
    int pick = notp;
    if (cnt0 <= m && cnt1 <= n) {
      pick = 1 + helper1(strs, idx + 1, m - cnt0, n - cnt1);
    }

    return max(notp, pick);
  }

  // DP two 2D array
  int func2(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp1(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp2(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < strs.size(); i++) {
      int cnt0 = 0;
      int cnt1 = 0;
      for (int j = 0; j < strs[i].length(); j++) {
        if (strs[i][j] == '0')
          cnt0++;
        if (strs[i][j] == '1')
          cnt1++;
      }
      for (int x = cnt0; x <= m; x++) {
        for (int y = cnt1; y <= n; y++) {
          dp1[x][y] = max(dp2[x][y], 1 + dp2[x - cnt0][y - cnt1]);
        }
      }
      for (int x = 0; x <= m; x++) {
        for (int y = 0; y <= n; y++) {
          dp2[x][y] = dp1[x][y];
        }
      }
      // for (int x = 0; x <= m; x++) {
      //     for (int y = 0; y <= n; y++) {
      //         cout << dp2[x][y] << " ";
      //     }
      //     cout << endl;
      // }
      // cout << "-------" << endl;
    }

    return dp1[m][n];
  }

  // DP one 2D array
  int func3(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp1(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < strs.size(); i++) {
      int cnt0 = 0;
      int cnt1 = 0;
      for (int j = 0; j < strs[i].length(); j++) {
        if (strs[i][j] == '0')
          cnt0++;
        if (strs[i][j] == '1')
          cnt1++;
      }
      for (int x = m; x >= cnt0; x--) {
        for (int y = n; y >= cnt1; y--) {
          dp1[x][y] = max(dp1[x][y], 1 + dp1[x - cnt0][y - cnt1]);
        }
      }
    }

    return dp1[m][n];
  }

  // 2020-02-05, review
  int func4(vector<string> &strs, int m, int n) {
    vector<vector<int>> kp(m + 1, vector<int>(n + 1, 0));
    int V0 = m;
    int V1 = n;

    for (auto s : strs) {
      int cnt0 = 0;
      int cnt1 = 0;
      for (auto c : s) {
        if (c == '0') {
          cnt0++;
        } else if (c == '1') {
          cnt1++;
        }
      }
      TwoDimensionPack(kp, V0, V1, cnt0, cnt1);
    }

    return kp[m][n];
  }
  void TwoDimensionPack(vector<vector<int>> &kp, int V0, int V1, int cost0,
                        int cost1) {
    for (int i = V0; i >= cost0; i--) {
      for (int j = V1; j >= cost1; j--) {
        kp[i][j] = max(kp[i][j], kp[i - cost0][j - cost1] + 1);
      }
    }
    return;
  }
};
