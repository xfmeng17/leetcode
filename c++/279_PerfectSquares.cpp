class Solution {
public:
    int numSquares(int n) {
        // return func1(n);
        return func2(n);  
    }

    // ** 0/1 knapsack 2D dp
    int func1(int n) {
        int m = sqrt(n);
        vector<int> squares(m);
        vector<vector<int>> dp(m+1, vector<int>(n+1, n));

        for (int i = 0; i < m; i++) {
            squares[i] = (i+1) * (i+1);
            dp[i+1][squares[i]] = 1;
        }

        for (int i = 1; i <= squares.size(); i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                if (j - squares[i-1] >= 0) {
                    int curr = 1 + dp[i][j - squares[i-1]];
                    dp[i][j] = min(dp[i][j], curr);
                }
            }
        }

        return dp[squares.size()][n];
    }

    // ** 1D array
    int func2(int n) {
        int m = sqrt(n);
        vector<int> squares(m);
        vector<int> dp(n+1, n);

        for (int i = 0; i < m; i++) {
            squares[i] = (i+1) * (i+1);
            dp[squares[i]] = 1;
        }
        
        for (int sqr : squares) {
            for (int j = sqr; j <= n; j++) {
                dp[j] = min(dp[j], 1 + dp[j - sqr]);
            }
        }

        return dp[n];
    }
};
