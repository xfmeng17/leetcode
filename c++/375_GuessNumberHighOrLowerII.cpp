class Solution {
public:
    int getMoneyAmount(int n) {
        // return func1(n);
        return func2(n);
    }

    // ** WA after n  = 20
    // ** mine output=51, expected=49, weird
    int func1(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        if (n <= 11) return 4 + (n - 4) * 2;
        
        return (n - 3) + getMoneyAmount(n-4);
    }

    // ** Great problem, that is why n=20, result=49
    // ** [1, 12], 13, [14, 20] => 13
    // ** [1, 12] => 21, [14, 20] => 36
    // ** total 13 + 36 = 49

    // ** 2D array dp
    int func2(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, n*n));

        // ** len = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }
        // ** len = 2;
        for (int i = 1; i <= n-1; i++) {
            dp[i][i+1] = i;
        }
        // ** len = 3;
        for (int i = 1; i <= n-2; i++) {
            dp[i][i+2] = i+1;
        }
        for (int len = 4; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int lo = i;
                int hi = i + len - 1;
                for (int mid = lo + 1; mid < hi; mid++) {
                    int curr = mid + max(dp[lo][mid-1], dp[mid+1][hi]);
                    dp[lo][hi] = min(dp[lo][hi], curr);
                }
            }
        }

        return dp[1][n];
    }
};
