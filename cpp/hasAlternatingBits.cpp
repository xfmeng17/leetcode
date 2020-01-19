class Solution {
public:
  /*
  bool hasAlternatingBits(int n) {
      int remainder = n % 2;
      int quotient = n / 2;
      while (quotient > 0) {
              if (quotient % 2 == remainder) {
                      return false;
              } else {
                      remainder = quotient % 2;
                      quotient = quotient / 2;
              }
      }

      return true;
  }
  */

  // ref
  bool hasAlternatingBits(int n) {
    n ^= n >> 2;
    return !(n & (n - 1));
  }
};
