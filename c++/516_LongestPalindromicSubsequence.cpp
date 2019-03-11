class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // return func1(s);
        return func2(s);
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

    // ** recursive + meme
    int func2(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        return helper2(s, 0, s.length() - 1, memo);
    }
    int helper2(string s, int lo, int hi, vector<vector<int>>& memo) {
        if (lo > hi) {
            return 0;
        }
        if (lo == hi) {
            return 1;
        }
        if (memo[lo][hi] > 0) {
            return memo[lo][hi];
        }

        if (s[lo] == s[hi]) {
            memo[lo][hi] = 2 + helper1(s, lo + 1, hi - 1);
        } else {
            int lf = helper2(s, lo, hi - 1, memo);
            int rt = helper2(s, lo + 1, hi, memo);
            memo[lo][hi] = max(lf, rt);
        }
        
        return memo[lo][hi];
    }
};
