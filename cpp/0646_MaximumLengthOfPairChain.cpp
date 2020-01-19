class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) { return func1(pairs); }

  int func1(vector<vector<int>> &pairs) {
    if (pairs.size() <= 0) {
      return 0;
    }
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    int ret = 1;
    int idx = 0;
    for (int i = 1; i < pairs.size(); i++) {
      if (pairs[idx][1] < pairs[i][0]) {
        idx = i;
        ret++;
      }
    }

    return ret;
  }
};
