func maxProfit(prices []int) int {
	// return func1(prices);
	// return func2(prices);
	// return func3(prices);
	// return func4(prices);
	return func5(prices);
}

// Sell at day i
func func1(prices []int) int {
	ret := 0;
	for i := 0; i < len(prices); i++ {
		ret = max(ret, helper1(prices, i));
	}
	return ret;
}
func helper1(prices []int, k int) int {
	if k <= 0 {
		return 0;
	}

	ret := 0;
	for i := k; i >= 0; i-- {
		cur := prices[k] - prices[i];
		pre := 0;
		for j := i-2; j >= 0; j-- {
			pre = max(pre, helper1(prices, j));
		}
		ret = max(ret, cur + pre);
	}
	return ret;
}
// TLE still
func func2(prices []int) int {
	ret := 0;
	memo := make([]int, len(prices));
	for i := 0; i < len(memo); i++ {
		memo[i] = -1;
	}
	for i := 0; i < len(prices); i++ {
		ret = max(ret, helper2(prices, i, memo));
	}
	return ret;
}
func helper2(prices []int, k int, memo []int) int {
	if k <= 0 {
		return 0;
	}
	if memo[k] >= 0 {
		return memo[k];
	}

	ret := 0;
	for i := k; i >= 0; i-- {
		cur := prices[k] - prices[i];
		pre := 0;
		for j := i-2; j >= 0; j-- {
			pre = max(pre, helper1(prices, j));
		}
		ret = max(ret, cur + pre);
	}
	memo[k] = ret;
	return ret;
}
/* So func1, func2 show that this `sell at day i` recursive thought
 * maybe wrong. Here is a new one, f[i] means most profit at 0...i:
 * f[i] = 1. sell at i => max{prices[i]-prices[j] + f[j-2]}, j=0...i-1
 *        2. not sell at i => f[i-1]
 */ 
func func3(prices []int) int {
	ret := 0;
	memo := make([]int, len(prices));
	for i := 0; i < len(memo); i++ {
		memo[i] = -1;
	}
	for i := 0; i < len(prices); i++ {
		ret = max(ret, helper3(prices, i, memo));
	}
	return ret;
}
func helper3(prices []int, i int, memo []int) int {
	if i < 0 {
		return 0;
	}
	if memo[i] >= 0 {
		return memo[i];
	}

	ret := helper3(prices, i-1, memo);
	for j := i-1; j >= 0; j-- {
		ret = max(ret, prices[i] - prices[j] + helper3(prices, j-2, memo));
	}
	memo[i] = ret;
	return ret;
}
func func4(prices []int) int {
	n := len(prices);
	memo := make([]int, n);
	if n <= 0 {
		return 0;
	}
	for i := 1; i < n; i++ {
		memo[i] = memo[i-1];
		for j := i; j >= 0; j-- {
			pre := 0;
			if j >= 2 {
				pre = memo[j-2];
			}
			memo[i] = max(memo[i], prices[i] - prices[j] + pre);
		}
	}

	return memo[n-1];
}
/*
 * The series-of-stock problems solution, k = +INF
 * T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])
 * T[i][1] = max(T[i-1][1], T[i-2][0] - prices[i])
 */
const INT_MAX = int(^uint(0) >> 1);
const INT_MIN = ^INT_MAX;

func func5(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}

	T_ik0 := 0;
	T_ik0_pre := 0;
	T_ik1 := INT_MIN;

	for i := 0; i < len(prices); i++ {
		T_ik0_aux := T_ik0;
		T_ik0 = max(T_ik0, T_ik1 + prices[i]);
		T_ik1 = max(T_ik1, T_ik0_pre - prices[i]);
		T_ik0_pre = T_ik0_aux;
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