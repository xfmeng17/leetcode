class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // return func1(A, B);
        return func2(A, B); 
    }
    // ** dp, time O(mn), space O(mn)
    int func1(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ret = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
                ret = max(ret, dp[i][j]);
            }
        }

        return ret;
    }

    // ** dp, time O(mn), space O(n)
    int func2(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();

        vector<int> dp(n+1, 0);
        int pre = 0;
        int ret = 0;

        for (int i = 1; i <= m; i++) {
            pre = 0;
            for (int j = 1; j <= n; j++) {
                int aux = pre;
                pre = dp[j];
                if (A[i-1] == B[j-1]) {
                    dp[j] = 1 + aux;
                } else {
                    dp[j] = 0;
                }
                ret = max(ret, dp[j]);
            }
        }
        return ret;
    }
};
