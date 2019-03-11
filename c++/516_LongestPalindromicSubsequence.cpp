class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return func1(s);
    }
    // ** still starting from recursion
    int func1(string s) {
        return helper1(s, 0, s.length() - 1);
    }
    int helper1(string s, int lo, int hi) {
        if (lo > hi) {
            return 0;
        }
        if (lo == hi) {
            return 1;
        }
        if (s[lo] == s[hi]) {
            return 2 + helper1(s, lo + 1, hi - 1);
        }

        int lf = helper1(s, lo, hi - 1);
        int rt = helper1(s, lo + 1, hi);

        return max(lf, rt);
    }

};
