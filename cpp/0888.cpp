class Solution {
public:
  vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
    // return func1(A, B);
    return func2(A, B);
  }
  vector<int> func1(vector<int> &A, vector<int> &B) {
    int ta = 0;
    int tb = 0;
    unordered_set<int> sa;
    unordered_set<int> sb;
    for (auto a : A) {
      ta += a;
      sa.insert(a);
    }
    for (auto b : B) {
      tb += b;
      sb.insert(b);
    }
    vector<int> res;
    int da = ta - ((ta + tb) / 2);
    for (auto a : A) {
      if (sb.count(a - da)) {
        res.push_back(a);
        res.push_back(a - da);
        return res;
      }
    }
    return res;
  }

  // ** elegant approach from reference
  vector<int> func2(vector<int> &A, vector<int> &B) {
    int diff = (accumulate(A.begin(), A.end(), 0) -
                accumulate(B.begin(), B.end(), 0)) /
               2;
    unordered_set<int> set(A.begin(), A.end());
    for (int b : B) {
      if (set.count(b + diff)) {
        return {b + diff, b};
      }
    }
  }
};
