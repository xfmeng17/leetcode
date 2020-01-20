class Solution {

  const int BASE_7 = 7;
  const int BASE_10 = 10;

public:
  string convertToBase7(int num) {
    // return func1(num);
    return func2(num);
  }

  string func1(int num) {
    vector<char> res;
    bool negative = false;
    if (num < 0) {
      num = -num;
      negative = true;
    }
    if (num == 0) {
      res.push_back('0');
    }
    while (num != 0) {
      res.push_back((num % BASE_7) + '0');
      num /= BASE_7;
    }
    if (negative) {
      res.push_back('-');
    }
    reverse(res.begin(), res.end());
    return string(res.begin(), res.end());
  }

  // ** more concise
  string func2(int num) {
    int res = 0;
    for (int i = 0; num != 0; i++) {
      res += pow(10, i) * (num % 7);
      num /= 7;
    }
    return to_string(res);
  }
};
