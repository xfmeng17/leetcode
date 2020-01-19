class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
    for (vector<int> &r : A) {
      int size = r.size();
      for (int i = 0; i < size / 2; i++) {
        int temp = r[i];
        r[i] = r[size - 1 - i] ^ 1;
        r[size - 1 - i] = temp ^ 1;
      }
      if (size % 2 == 1) {
        r[size / 2] ^= 1;
      }
    }
    return A;
  }
};