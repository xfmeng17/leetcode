class Solution {
public:
    int climbStairs(int n) {
    	if (n == 0) return 0;
    	if (n == 1) return 1;
    	if (n == 2) return 2;

    	int dp1 = 1;
    	int dp2 = 2;

    	while (n-- >= 3) {
    		int cur = dp1 + dp2;
    		dp1 = dp2;
    		dp2 = cur;
    	}

    	return dp2;
    }
};
