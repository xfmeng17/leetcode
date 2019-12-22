class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        return func1(coins, amount);
    }

    // ** standard completely 0/1 knapsack
    int func1(vector<int>& coins, int amount) {
    	vector<int> dp(amount + 1, amount + 1);
    	dp[0] = 0;
    	
    	for (auto coin : coins) {
    		for (int i = 0; i <= amount; i++) {
    			if (i - coin >= 0) {
    				dp[i] = min(dp[i], dp[i-coin] + 1);
    			}
    		}
    	}
    	return dp[amount] < amount + 1 ? dp[amount] : -1; 
    }
};