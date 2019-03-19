class Solution {
public:
    int numSquares(int n) {
        return func1(n);  
    }

    // ** 0/1 knapsack 2D dp
    int func1(int n) {
        vector<int> squares;
        for (int i = 1; (i * i) <= n; i++) {
            squares.push_back(i*i);
        }
        vector<vector<int>> dp(squares.size()+1, vector<int>(n+1, n));
        for (int i = 0; i < squares.size(); i++) {
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
};
