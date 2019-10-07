class Solution {
public:
	const int MOD = 1e9 + 7;
public:
    int numTilings(int N) {
    	return func1(N);
    }

    // ** dp[i] = 2 * dp[i-1] + dp[i-3]
    int func1(int N) {
    	int dp1 = 1;
    	int dp2 = 2;
    	int dp3 = 5;

    	if (N <= 0) return 0;
    	if (N == 1) return dp1;
    	if (N == 2) return dp2;
    	if (N == 3) return dp3;

    	while (N-- >= 4) {
    		int dp4 = (2 * dp3 % MOD + dp1) % MOD;
    		dp1 = dp2;
    		dp2 = dp3;
    		dp3 = dp4;
    	}

    	return dp3;
    }
};
