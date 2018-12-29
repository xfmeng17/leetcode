class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	unordered_map<int, int> dp;
    	return min(func1(cost, 0, dp), func1(cost, 1, dp));   
    }

	// ** don't store result into dp will cause TLE.
	int func1(vector<int>& cost, int i, unordered_map<int, int>& dp) {
		if (dp[i]) {
			return dp[i];
		}
		if (i >= cost.size()) {
			return 0;
		}
		int one = cost[i] + func1(cost, i + 1, dp);
		int two = cost[i] + func1(cost, i + 2, dp);
		dp[i] = min(one, two);
		return dp[i];
	}
	// ** I think there are another approach let down to top
	int func2() {
		return 0;
	}    
};
