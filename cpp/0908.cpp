class Solution {
public:
  int smallestRangeI(vector<int> &A, int K) {
    int max = A[0];
    int min = A[0];
    for (int a : A) {
      if (a > max)
        max = a;
      if (a < min)
        min = a;
    }
    return max - min - 2 * K > 0 ? max - min - 2 * K : 0;
  }
};