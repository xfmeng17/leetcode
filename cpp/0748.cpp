class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    return func1(licensePlate, words);
  }

  string func1(string licensePlate, vector<string> &words) {
    int lpSet[26] = {0};
    for (char c : licensePlate) {
      if (isalpha(c)) {
        lpSet[tolower(c) - 'a']++;
      }
    }
    int shortest = -1;
    for (int i = 0; i < words.size(); i++) {
      int wdSet[26] = {0};
      for (char c : words[i]) {
        wdSet[c - 'a']++;
      }
      int j = 0;
      for (j; j < 26; j++) {
        if (wdSet[j] < lpSet[j])
          break;
      }
      if (j == 26) {
        if (shortest == -1) {
          shortest = i;
        } else {
          if (words[i].length() < words[shortest].length()) {
            shortest = i;
          }
        }
      }
    }
    return words[shortest];
  }
};