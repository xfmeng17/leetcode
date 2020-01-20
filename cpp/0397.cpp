class Solution {
public:
  int integerReplacement(int n) {
    // return func1(n);
    return func2(n);
  }

  int func1(int n) {
    if (n == 1) {
      return 0;
    }

    if (n % 2 == 0) {
      return 1 + func1(n / 2);
    }

    return 1 + min(func1(n + 1), func1(n - 1));
  }

  //** Input: 2147483647, Runtime Error
  int func2(int n) {
    unordered_map<long, int> memo;
    return helper2(n, memo);
  }
  int helper2(long long n, unordered_map<long, int> &memo) {
    if (n == 1) {
      return 0;
    }

    if (memo.find(n) != memo.end()) {
      return memo[n];
    }

    if (n % 2 == 0) {
      memo[n] = 1 + helper2(n / 2, memo);
      return memo[n];
    }

    memo[n] = 1 + min(helper2(n + 1, memo), helper2(n - 1, memo));
    return memo[n];
  }
};