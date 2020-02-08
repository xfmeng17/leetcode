class Solution {
public:
    int superEggDrop(int K, int N) {
        return func1(K, N);
    }

    /*
     * Reference solution:
     * dp[m][k] denotes that given `k` eggs and `m` moves, what is the maximum
     * number of floors that we can check.
     *
     * dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1
     *
     * Which means we take 1 move to a floor,
     * if egg breaks, then we can check dp[m - 1][k - 1] floors.
     * if egg doesn't breaks, then we can check dp[m - 1][k - 1] floors.
     *
     * And the trick key to understand `dp[m-1][k-1] + dp[m-1][k]` is, no
     * matter egg break or not break, we always can know the other condition in
     * the same time !!!
     */
    int func1(int K, int N) {
        vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
        int m = 0;

        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; k++) {
                dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1;
            }
        }

        return m;
    }
};