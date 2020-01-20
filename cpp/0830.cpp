class Solution {
public:
  vector<vector<int>> largeGroupPositions(string S) { return func1(S); }

  vector<vector<int>> func1(string S) {
    vector<vector<int>> res;
    int bgn = 0;
    int end = 0;
    bool large = false;
    for (int i = 1; i < S.length(); i++) {
      if (S[i] == S[i - 1]) {
        if (i - bgn + 1 >= 3) {
          large = true;
          end = i;
        }
      } else {
        if (large) {
          res.push_back({bgn, end});
        }
        bgn = i;
        large = false;
      }
    }
    if (large) {
      res.push_back({bgn, end});
    }

    return res;
  }
};
