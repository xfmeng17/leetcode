class Solution {
public:
  bool checkRecord(string s) {
    int a = 0, l = 0;
    for (auto x : s) {
      if (x == 'A')
        a++;
      if (x == 'L')
        l++;
      if (a > 1 || l > 2)
        return false;
      if (x != 'L')
        l = 0;
    }
    return true;
  }
};
