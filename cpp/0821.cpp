class Solution {
public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> res(S.length());
    for (int i = 0; i < S.length(); i++) {
      if (S[i] == C) {
        res[i] = 0;
      } else {
        int lf = i - 1;
        int rt = i + 1;
        bool find = false;
        while (!find) {
          if (lf >= 0 && S[lf] == C) {
            res[i] = i - lf;
            find = true;
          } else {
            lf--;
          }
          if (rt < S.length() && S[rt] == C) {
            res[i] = rt - i;
            find = true;
          } else {
            rt++;
          }
          if (lf < 0 && rt > S.length()) {
            res[i] = -1;
            find = true;
          }
        }
      }
    }
    return res;
  }
};
