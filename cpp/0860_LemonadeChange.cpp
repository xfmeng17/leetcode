class Solution {
public:
  bool lemonadeChange(vector<int> &bills) { return func1(bills); }

  bool func1(vector<int> &bills) {
    int dollar_5 = 0;
    int dollar_10 = 0;
    for (int b : bills) {
      if (b == 5) {
        dollar_5++;
      } else if (b == 10) {
        dollar_5--;
        dollar_10++;
        if (dollar_5 < 0) {
          return false;
        }
      } else if (b == 20) {
        if (dollar_10 > 0) {
          dollar_10--;
          dollar_5--;
          if (dollar_10 < 0 || dollar_5 < 0) {
            return false;
          }
        } else {
          dollar_5 -= 3;
          if (dollar_5 < 0) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
