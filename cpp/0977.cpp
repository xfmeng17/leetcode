class Solution {
public:
  vector<int> sortedSquares(vector<int> &A) { return func1(A); }
  // ** two pointer
  vector<int> func1(vector<int> &A) {
    vector<int> res;

    int lf = -1, rt = -1;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] > 0) {
        rt = i;
        lf = i - 1;
        break;
      }
    }
    if (rt == -1) {
      rt = A.size();
      lf = rt - 1;
    }

    while (lf >= 0 && rt < A.size()) {
      if (A[lf] * A[lf] < A[rt] * A[rt]) {
        res.push_back(A[lf] * A[lf]);
        lf--;
      } else {
        res.push_back(A[rt] * A[rt]);
        rt++;
      }
    }

    while (lf >= 0) {
      res.push_back(A[lf] * A[lf]);
      lf--;
    }
    while (rt < A.size()) {
      res.push_back(A[rt] * A[rt]);
      rt++;
    }

    return res;
  }
};