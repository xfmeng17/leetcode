class Solution {
public:
  int findSubstringInWraproundString(string p) {
    // return func1(p);
    // return func2(p);
    return func3(p);
  }

  // ** wa, bad case: "zaba"
  // ** I double count "a" but "zab" already count a

  /* 	Update190325 use iteration with a vector to filter
          the substrings already exists.
          But WA the same cause can't solve circulation like this:
          "a..za...za...z"
  */
  int func1(string p) {
    unordered_set<string> table;
    int lo = 0;
    int hi = 1;
    while (hi < p.length()) {
      int diff = (p[hi] + 26 - p[hi - 1]) % 26;
      if (diff == 1) {
        hi++;
      } else {
        string s = p.substr(lo, hi - lo);
        if (table.count(s) <= 0) {
          table.insert(s);
        }
        lo = hi;
        hi++;
      }
    }

    string s = p.substr(lo, hi - lo);
    if (table.count(s) <= 0) {
      table.insert(s);
    }

    // int res = 0;
    // for (auto it = table.begin(); it != table.end(); it++) {
    // 	int len = (*it).length();
    // 	res += (1 + len) * len / 2;
    // }

    vector<string> list(table.begin(), table.end());
    vector<bool> find(table.size(), false);
    for (int i = 0; i < list.size(); i++) {
      for (int j = 0; j < list.size(); j++) {
        if (i == j)
          continue;
        if (list[j].find(list[i]) != string::npos) {
          find[i] = true;
          break;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < list.size(); i++) {
      // cout << list[i] << ": " << find[i] << endl;
      if (!find[i]) {
        int len = list[i].length();
        res += (1 + len) * len / 2;
      }
    }

    return res;
  }

  // ** use a extra helper function putSubstring()
  // ** TLE
  int func2(string p) {
    if (p.length() <= 0) {
      return 0;
    }

    unordered_set<string> table;
    int lo = 0;
    int hi = 1;
    while (hi < p.length()) {
      int diff = (p[hi] + 26 - p[hi - 1]) % 26;
      if (diff == 1) {
        hi++;
      } else {
        putSubstring(p, lo, hi - 1, table);
        lo = hi;
        hi++;
      }
    }
    putSubstring(p, lo, hi - 1, table);

    return table.size();
  }

  void putSubstring(string p, int lo, int hi, unordered_set<string> &table) {
    if (lo > hi)
      return;

    for (int len = hi - lo + 1; len >= 1; len--) {
      for (int i = lo, j = lo + len - 1; j <= hi; i++, j++) {
        string s = p.substr(i, len);
        if (table.count(s) <= 0) {
          // cout << table.size() << " = " << s << endl;
          table.insert(s);
        }
      }
    }
  }

  // ** reference, not dp really
  int func3(string p) {
    int count[26] = {0};
    int len = 1;
    for (int i = 0; i < p.length(); i++) {
      if (i > 0 && (p[i] + 26 - p[i - 1]) % 26 == 1) {
        len++;
      } else {
        len = 1;
      }
      count[p[i] - 'a'] = max(count[p[i] - 'a'], len);
    }

    int res = 0;
    for (auto c : count)
      res += c;

    return res;
  }
};