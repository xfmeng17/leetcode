class Solution {
public:
  int numSpecialEquivGroups(vector<string> &A) {
    // return func1(A);
    return func2(A);
  }

  int func1(vector<string> &A) {
    unordered_map<string, int> map;
    for (string str : A) {
      map[formatStr(str)]++;
    }
    return map.size();
  }

  string formatStr(string str) {
    char set[26] = {0};
    string res = "";

    for (int i = 0; i < str.length(); i += 2) {
      set[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (set[i] > 0) {
        res += (char)('a' + i) + to_string(set[i]);
        set[i] = 0;
      }
    }
    res += '_';
    for (int i = 1; i < str.length(); i += 2) {
      set[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (set[i] > 0) {
        res += (char)('a' + i) + to_string(set[i]);
        set[i] = 0;
      }
    }
    return res;
  }

  // ** referance sort
  int func2(vector<string> &A) {
    unordered_set<string> s;
    for (const auto &w : A) {
      string odd, even;
      for (int i = 0; i < w.length(); i++) {
        if (i % 2)
          even += w[i];
        else
          odd += w[i];
      }
      sort(even.begin(), even.end());
      sort(odd.begin(), odd.end());
      s.insert(even + odd);
    }
    return s.size();
  }
};