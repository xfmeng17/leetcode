class Solution {
public:
  vector<int> diStringMatch(string S) {
    vector<int> res;
    int inc = 0;
    int dec = S.length();
    for (int i = 0; i < S.length(); i++) {
      switch (S[i]) {
      case 'I':
        res.push_back(inc++);
        break;
      case 'D':
        res.push_back(dec--);
        break;
      default:
        break;
      }
    }
    res.push_back(inc);
    return res;
  }
};
