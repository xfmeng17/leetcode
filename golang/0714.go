func maxProfit(prices []int, fee int) int {
	return func4(prices, fee)
}

// Copy from 309: Best Time to Buy and Sell Stock with Cooldown
// !!Notice change `j >= 2` check to `j >= 1` because this is no cool down
// But TLE, there is O(n) time solution?
func func4(prices []int, fee int) int {
	n := len(prices);
	memo := make([]int, n);
	if n <= 0 {
		return 0;
	}
	for i := 1; i < n; i++ {
		memo[i] = memo[i-1];
		for j := i; j >= 0; j-- {
			pre := 0;
			if j >= 1 {
				pre = memo[j-1];
			}
			memo[i] = max(memo[i], prices[i] - prices[j] - fee + pre);
		}
	}

	return memo[n-1];
}

// Helper functions
func max(a int, b int) int {
	if a > b {
		return a;
	}
	return b;
}