class Solution {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    // return func1(maxChoosableInteger, desiredTotal);
    return func2(maxChoosableInteger, desiredTotal);
  }

  // ** backtracking
  bool func1(int maxChoosableInteger, int desiredTotal) {
    vector<bool> used(maxChoosableInteger + 1, false);
    if (desiredTotal <= 0) {
      return true;
    }
    return helper1(maxChoosableInteger, desiredTotal, 1, used);
  }

  bool helper1(int maxChoosableInteger, int desiredTotal, int player,
               vector<bool> &used) {

    if (desiredTotal <= 0) {
      return player == 2;
    }

    int currPlayer = player == 1 ? 2 : 1;
    if (player == 1) {
      bool res = true;
      for (int i = 1; i <= maxChoosableInteger; i++) {
        if (!used[i]) {
          used[i] = true;
          res &=
              helper1(maxChoosableInteger, desiredTotal - i, currPlayer, used);
          used[i] = false;
        }
      }
      return res;
    } else {
      bool res = false;
      for (int i = 1; i <= maxChoosableInteger; i++) {
        if (!used[i]) {
          used[i] = true;
          res |=
              helper1(maxChoosableInteger, desiredTotal - i, currPlayer, used);
          used[i] = false;
        }
      }
      return res;
    }
  }

  // ** Reference, recursive + memoization
  // ** Kye point is how to cache subproblems
  bool func2(int maxChoosableInteger, int desiredTotal) {
    int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
    if (sum < desiredTotal)
      return false;
    if (desiredTotal <= 0)
      return true;

    unordered_map<int, bool> memo;
    vector<bool> marked(maxChoosableInteger + 1, false);

    return helper2(desiredTotal, marked, memo);
  }

  bool helper2(int desiredTotal, vector<bool> &marked,
               unordered_map<int, bool> &memo) {

    if (desiredTotal <= 0)
      return false;

    int key = format(marked);
    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    for (int i = 1; i < marked.size(); i++) {
      if (marked[i])
        continue;

      marked[i] = true;
      if (!helper2(desiredTotal - i, marked, memo)) {
        memo[key] = true;
        marked[i] = false;
        return true;
      }
      marked[i] = false;
    }

    memo[key] = false;
    return false;
  }

  int format(vector<bool> &marked) {
    int num = 0;
    for (int i = marked.size() - 1; i >= 1; i--) {
      if (marked[i]) {
        num |= 1;
      }
      num = num << 1;
    }
    return num;
  }
};