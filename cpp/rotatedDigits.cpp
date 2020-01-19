class Solution {
public:
  int rotatedDigits(int N) {
    // return func1(N);
    return func2(N);
  }

  // brute force O(N*logN) (logN is based at 10)
  int func1(int N) {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
      bool res = false;
      int x = i;
      while (x) {
        int r = x % 10;
        if (r == 2 || r == 5 || r == 6 || r == 9) {
          res = true;
        } else if (r == 3 || r == 4 || r == 7) {
          res = false;
          break;
        } else {
          // nothing to do for 0, 1, 8
        }
        x = x / 10;
      }
      if (res) {
        ans++;
      }
    }
    return ans;
  }

  // ref: DP O(logN + 1) (logN is based at 10)
  int func2(N) {
    // TODO
  }
};
