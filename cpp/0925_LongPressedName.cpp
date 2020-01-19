class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    int m = 0;
    int n = 0;
    while (m < name.length() && n < typed.length()) {
      if (name[m] != typed[n]) {
        if (m == 0 || name[m - 1] != typed[n]) {
          return false;
        } else {
          n++;
        }
      } else {
        m++;
        n++;
      }
    }

    return m == name.length();
  }
};
