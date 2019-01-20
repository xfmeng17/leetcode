class Solution {
public:
    int climbStairs(int n) {
		// return func1(n); 
		return func2(n);
    }
    // ** F(n) = F(n-1) + F(n-2)
    int func1(int n) {
    	vector<int> memo(n+1);
    	memo[1] = 1;
    	memo[2] = 2;
    	return helper1(n, memo);
    }
    int helper1(int n, vector<int>& memo) {
    	if (n <= 0) return 0;
    	if (memo[n] > 0) return memo[n];
    	memo[n] = helper1(n-1, memo) + helper1(n-2, memo);
    	return memo[n];
    }
    // ** trim space
    int func2(int n) {
    	if (n <= 0) return 0;
    	if (n == 1) return 1;
    	if (n == 2) return 2;

    	int dp1 = 1;
    	int dp2 = 2;
    	for (int i = 3; i <= n; i++) {
    		int cur = dp1 + dp2;
    		dp1 = dp2;
    		dp2 = cur;
    	}

    	return dp2;
    }
};
