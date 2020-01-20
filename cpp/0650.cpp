class Solution {
public:
  int minSteps(int n) {
    // return func1(n);
    return func2(n);
  }
  int func1(int n) {
    if (n <= 1) {
      return 0;
    }
    return 1 + helper1(n, 1, 1);
  }
  int helper1(int target, int notepad, int paste) {
    if (target == notepad) {
      return 0;
    }
    if (target < notepad) {
      return target;
    }

    int p = 1 + helper1(target, notepad + paste, paste);
    int c = p;
    if (notepad != paste) {
      c = 1 + helper1(target, notepad, notepad);
    }

    return min(p, c);
  }

  // ** reference, pure dp
  int func2(int n) {
    vector<int> dp(n + 1, n);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (i % j != 0) {
          continue;
        }
        dp[i] = min(dp[i], (i / j) + dp[j]);
      }
    }

    return dp[n];
  }
};
