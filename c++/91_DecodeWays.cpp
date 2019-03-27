class Solution {
public:
    int numDecodings(string s) {
    	// return func1(s);
    	return func2(s);
    }

    // ** dp[i] = dp[i-1] + { dp[i-2] if nums[i-1][i] < 26 }
    // ** Notice the lead '0': input "01", return 0
    int func1(string s) {
    	int N = s.length();
    	if (N <= 0) {
    		return 0;
    	}

        vector<double> dp(N+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= N; i++) {
        	if (s[i-1] != '0') {
        		dp[i] += dp[i-1];
        	}
        	if (i >= 2 && s[i-2] != '0') {
        		int n = (s[i-2] - '0') * 10 + (s[i-1] - '0');
        		if (n >= 1 && n <= 26) {
        			dp[i] += dp[i-2];
        		}
        	}
        }

        return dp[N];
    }

    int func2(string s) {
    	int N = s.length();
    	if (N <= 0) {
    		return 0;
    	}

    	int dp0 = 1;
    	int dp1 = s[0] != '0' ? 1 : 0;

    	for (int i = 1; i < N; i++) {
    		int dp2 = 0;
    		if (s[i] != '0') {
    			dp2 += dp1;
    		}
    		if (s[i-1] != '0') {
    			int n = (s[i-1] - '0') * 10 + (s[i] - '0');
    			if (n >= 1 && n <= 26) {
        			dp2 += dp0;
        		}
    		}
    		dp0 = dp1;
    		dp1 = dp2;
    	}

    	return dp1;
    }
};