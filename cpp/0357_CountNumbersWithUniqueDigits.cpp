class Solution {
public:
  int countNumbersWithUniqueDigits(int n) { return func1(n); }

  int func1(int n) {
    if (n <= 0)
      return 1;
    if (n == 1)
      return 10;
    if (n == 2)
      return 91;

    int N = min(n, 10);
    int dp = 91;
    int cnt = 9 * 9;
    int nxt = 8;
    for (int i = 3; i <= N; i++) {
      cnt *= nxt;
      nxt--;
      dp += cnt;
    }

    return dp;
  }
};
