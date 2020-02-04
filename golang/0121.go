func maxProfit(prices []int) int {
	// return func1(prices);
	// return func2(prices);
	// return func3(prices);
	return func4(prices);
}

func func1(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}
	ret := 0;
	min := prices[0];
	for i := 1; i < len(prices); i++ {
		if prices[i] - min > ret {
			ret = prices[i] - min;
		}
		if prices[i] < min {
			min = prices[i];
		}
	}
	return ret;
}

/* 
 * The series-of-stock-problems: `T[i][k][s]` denotes the maximum profit at the
 * end of the `i-th` day with at most `k` transcations and with `s` stocks in
 * our hand AFTER taking the action. `s` = 0 or 1.
 *
 * 3 actions: buy, sell and rest.
 *
 * Base cases:
 * T[-1][k][0] = 0, T[-1][k][1] = -INF
 * T[i][0][0] = 0, T[i][0][1] = -INF
 * 
 * Recurrence relations:
 * T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
 * T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i]);
 *
 * In practice, sign T[0] will make coding easier
 * T[0][0][0] = 0
 * T[0][0][1] = -INF
 * T[0][1][0] = 0
 * T[0][1][1] = 0 - prices[0]
 */

const INT_MAX = int(^uint(0) >> 1);
const INT_MIN = ^INT_MAX;

func func2(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}

	n := len(prices);
	k := 1;
	T := make([][][]int, n);
	for i := 0; i < n; i++ {
		T[i] = make([][]int, k+1);
		for j := 0; j < k+1; j++ {
			T[i][j] = make([]int, 2);
		}
	}

	// Base
	T[0][0][0] = 0;
	T[0][0][1] = INT_MIN;
	T[0][1][0] = 0;
	T[0][1][1] = 0 - prices[0];

	// 1. T[i-1][0][0] always equals 0
	// 2. Never use T[i][0][1], which are all -INF
	// 3. So just need to keep T[i]_1_0 and T[i]_1_1
	for i := 1; i < n; i++ {
		T[i][0][0] = 0;
		T[i][0][1] = INT_MIN;
		T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i]);
		T[i][1][1] = max(T[i-1][1][1], T[i-1][0][0] - prices[i]);
	}
	
	return T[n-1][1][0];
}
// Like func2(), but O(1) space
func func3(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}

	n := len(prices);

	T_1_0 := 0;
	T_1_1 := 0 - prices[0];

	for i := 1; i < n; i++ {
		T_1_0 = max(T_1_0, T_1_1 + prices[i]);
		T_1_1 = max(T_1_1, 0 - prices[i]);
	}

	return T_1_0;
}
// Like func3(), but start from i=-1, keep same to reference
func func4(prices []int) int {
    if len(prices) <= 0 {
        return 0;
    }

    T_i10 := 0;
    T_i11 := INT_MIN;

    for i := 0; i < len(prices); i++ {
        T_i10 = max(T_i10, T_i11 + prices[i]);
        T_i11 = max(T_i11, 0 - prices[i]);
    }

    return T_i10;
}

// Helper functions
func max(a int, b int) int {
	if a > b {
		return a;
	}
	return b;
}
