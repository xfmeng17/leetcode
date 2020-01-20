class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    // return func1(s, wordDict);
    return func2(s, wordDict);
  }

  // ** 2D array dp
  // ** dp[i][j] stores s[i, j] is in-table or not
  // ** time O(N^3), AC but not fast enough
  bool func1(string s, vector<string> &wordDict) {
    int N = s.length();
    if (N <= 0) {
      return true;
    }

    vector<vector<bool>> dp(N, vector<bool>(N, false));
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    for (int i = 0; i < N; i++) {
      if (dict.count(string(1, s[i])) > 0) {
        dp[i][i] = true;
      }
    }
    for (int len = 2; len <= N; len++) {
      for (int lo = 0, hi = len - 1; hi < N; lo++, hi++) {
        if (dict.count(s.substr(lo, len)) > 0) {
          dp[lo][hi] = true;
          continue;
        }
        for (int mid = lo; mid < hi; mid++) {
          if (dp[lo][mid] && dp[mid + 1][hi]) {
            dp[lo][hi] = true;
            break;
          }
        }
      }
    }

    return dp[0][N - 1];
  }

  // ** 1D array dp
  // ** dp[i] stores s[0, i] is in-table or not
  // ** time O(N^2) if ignore substr(), AC really fast
  bool func2(string s, vector<string> &wordDict) {
    int N = s.length();
    if (N <= 0) {
      return true;
    }

    vector<bool> dp(N, false);
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    for (int i = 0; i < N; i++) {
      if (dict.count(s.substr(0, i + 1)) > 0) {
        dp[i] = true;
        continue;
      }
      for (int j = i; j > 0; j--) {
        if (dp[j - 1] && dict.count(s.substr(j, i - j + 1)) > 0) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[N - 1];
  }
};
