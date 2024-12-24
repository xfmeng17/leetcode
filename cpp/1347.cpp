class Solution {
public:
  int minSteps(string s, string t) {
    unordered_map<char, int> map;
    for (char c : s) {
      map[c]++;
    }
    for (char c : t) {
      if (map.find(c) != map.end()) {
        if (map[c] > 0) {
          map[c]--;
        }
      }
    }

    int ret = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
      ret += it->second;
    }
    return ret;
  }
};