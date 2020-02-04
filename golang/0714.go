func maxProfit(prices []int, fee int) int {
	// return func4(prices, fee);
	return func5(prices, fee);
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

/*
 * The series-of-stock problems
 * T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])
 * T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i] - fee)
 */
const INT_MAX = int(^uint(0) >> 1);
const INT_MIN = ^INT_MAX;
func func5(prices []int, fee int) int {
	if len(prices) <= 0 {
		return 0;
	}

	T_ik0 := 0;
	T_ik1 := INT_MIN;

	for i := 0; i < len(prices); i++ {
		T_ik0_aux := T_ik0;
		T_ik0 = max(T_ik0, T_ik1 + prices[i]);
		T_ik1 = max(T_ik1, T_ik0_aux - prices[i] - fee);
	}

	return T_ik0;
}

// Helper functions
func max(a int, b int) int {
	if a > b {
		return a;
	}
	return b;
}