class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return func1(strs, m, n);
    }

    // ** recursive
    int func1(vector<string>& strs, int m, int n) {
        return helper1(strs, 0, m, n);
    }
    int helper1(vector<string>& strs, int idx, int m, int n) {
        if (idx >= strs.size()) {
            return 0;
        }

        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < strs[idx].length(); i++) {
            if (strs[idx][i] == '0') cnt0++;
            if (strs[idx][i] == '1') cnt1++;
        }

        int notp = helper1(strs, idx+1, m, n);
        int pick = notp;
        if (cnt0 <= m && cnt1 <= n) {
            pick = 1 + helper1(strs, idx+1, m-cnt0, n-cnt1);
        }

        return max(notp, pick);
    }
};
