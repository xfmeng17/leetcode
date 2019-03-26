class Solution {
public:
    double new21Game(int N, int K, int W) {
    	return func1(N, K, W);
    }

    /* dp[i] represents the total probability to
	 * get point i.
	 * dp[i] = dp[i-1] * (1/W) + ... + dp[i-W] * (1/W) 
	*/
    double func1(int N, int K, int W) {
    	if (K == 0 || N >= K + W) {
    		return 1.0;
    	}

    	int maxPoint = K + W - 1;
        vector<double> dp(maxPoint + 1, 0.0);
        dp[0] = 1.0;
        
        for (int i = 1; i <= maxPoint; i++) {
        	for (int j = 1; j <= W; j++) {
        		if (i - j >= 0 && i - j < K) {
        			dp[i] += dp[i - j] * (1.0 / W);
        		}
        	}
        }
        // for (int i = 0; i <= maxPoint; i++) {
        // 	cout << i << "= " << dp[i] << endl;
        // }

        double res = 0.0;
        for (int i = K; i <= maxPoint; i++) {
        	if (i <= N) {
        		res += dp[i];
        	}
        }

        return res;
    }
};
