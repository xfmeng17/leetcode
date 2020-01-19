class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    while (left <= right) {
      int r = left % 10;
      int q = left / 10;
      while (q > 0) {
        if ((r == 0) || (left % r != 0)) {
          break;
        } else {
          r = q % 10;
          q = q / 10;
        }
      }
      if ((q == 0) && (left % r == 0)) {
        res.push_back(left);
      }
      left++;
    }
    return res;
  }
};
