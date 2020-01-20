class Solution {
public:
  bool isAlienSorted(vector<string> &words, string order) {
    return func1(words, order);
  }

  bool func1(vector<string> &words, string order) {
    int alpha[26] = {-1};

    for (int i = 0; i < order.length(); i++) {
      alpha[order[i] - 'a'] = i;
    }
    for (int i = 1; i < words.size(); i++) {
      if (alienCompare(words[i - 1], words[i], alpha)) {
        return false;
      }
    }

    return true;
  }

  bool alienCompare(const string &a, const string &b, const int *alpha) {
    int i = 0;
    for (; i < a.length() && i < b.length(); i++) {
      if (alpha[a[i] - 'a'] < alpha[b[i] - 'a']) {
        return false;
      } else if (alpha[a[i] - 'a'] > alpha[b[i] - 'a']) {
        return true;
      } else {
      }
    }

    return i == a.length() ? false : true;
  }
};
