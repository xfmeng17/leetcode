class Solution {
public:
  string gcdOfStrings(string str1, string str2) { return func1(str1, str2); }

  string func1(string str1, string str2) {
    string txt = str1.length() > str2.length() ? str1 : str2;
    string pat = str1.length() > str2.length() ? str2 : str1;

    int len = pat.length() + 1;
    while (--len > 0) {
      if (pat.length() % len != 0 || txt.length() % len != 0) {
        continue;
      }

      //** check pattern
      int patSectionNum = pat.length() / len;
      bool patDoCheck = true;
      for (int sec = 0; sec < patSectionNum && patDoCheck; sec++) {
        for (int i = 0; i < len; i++) {
          if (pat[i] != pat[i + len * sec]) {
            patDoCheck = false;
            break;
          }
        }
      }
      if (!patDoCheck) {
        continue;
      }
      //** check text
      int txtSectionNum = txt.length() / len;
      bool txtDoCheck = true;
      for (int sec = 0; sec < txtSectionNum && txtDoCheck; sec++) {
        for (int i = 0; i < len; i++) {
          if (pat[i] != txt[i + len * sec]) {
            txtDoCheck = false;
            break;
          }
        }
      }
      if (!txtDoCheck) {
        continue;
      }

      return pat.substr(0, len);
    }
    return "";
  }
};
