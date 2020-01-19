class Solution {
public:
  int knightDialer(int N) { return func1(N); }

  // ** dp1[i][j] represent the k move result
  // ** dp2[i][j] represent the (k-1) move result
  int func1(int N) {
    vector<vector<long>> dp1(4, vector<long>(3, 1));
    vector<vector<long>> dp2(4, vector<long>(3, 1));

    dp1[3][0] = 0;
    dp1[3][2] = 0;
    dp2[3][0] = 0;
    dp2[3][2] = 0;
    long modulo = pow(10, 9) + 7;

    for (int k = 2; k <= N; k++) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
          dp1[i][j] = 0;
          if (i == 3 && j == 0)
            continue;
          if (i == 3 && j == 2)
            continue;
          if (i - 2 >= 0 && j - 1 >= 0) {
            dp1[i][j] += dp2[i - 2][j - 1];
            dp1[i][j] %= modulo;
          }
          if (i - 1 >= 0 && j - 2 >= 0) {
            dp1[i][j] += dp2[i - 1][j - 2];
            dp1[i][j] %= modulo;
          }
          if (i + 1 < 4 && j - 2 >= 0) {
            dp1[i][j] += dp2[i + 1][j - 2];
            dp1[i][j] %= modulo;
          }
          if (i + 2 < 4 && j - 1 >= 0) {
            dp1[i][j] += dp2[i + 2][j - 1];
            dp1[i][j] %= modulo;
          }
          if (i + 2 < 4 && j + 1 < 3) {
            dp1[i][j] += dp2[i + 2][j + 1];
            dp1[i][j] %= modulo;
          }
          if (i + 1 < 4 && j + 2 < 3) {
            dp1[i][j] += dp2[i + 1][j + 2];
            dp1[i][j] %= modulo;
          }
          if (i - 1 >= 0 && j + 2 < 3) {
            dp1[i][j] += dp2[i - 1][j + 2];
            dp1[i][j] %= modulo;
          }
          if (i - 2 >= 0 && j + 1 < 3) {
            dp1[i][j] += dp2[i - 2][j + 1];
            dp1[i][j] %= modulo;
          }
        }
      }

      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
          dp2[i][j] = dp1[i][j];
        }
      }
    }

    long res = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        res += dp1[i][j];
        res %= modulo;
      }
    }

    return res;
  }
};
