func maxProfit(prices []int) int {
    return func1(prices);
}

/*
 * The series-of-stock problems
 * T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
 * T[i][k][1] = max(T[i-1][1], T[i-1][k-1][0] - prices[i])
 */

const INT_MAX = int(^uint(0) >> 1);
const INT_MIN = ^INT_MAX;

func func1(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}

	n := len(prices);
	k := 2;
	T := make([][][]int, n);
	for i := 0; i < n; i++ {
		T[i] = make([][]int, k+1);
		for j := 0; j <= k; j++ {
			T[i][j] = make([]int, 2);
		}
	}

	// Base
	T[0][0][0] = 0;
	T[0][0][1] = INT_MIN;
	T[0][1][0] = 0;
	T[0][1][1] = 0 - prices[0];
	T[0][2][0] = 0;
	T[0][2][1] = 0 - prices[0];

	for i := 1; i < n; i++ {
		T[i][0][0] = 0;
		T[i][0][1] = INT_MIN;
		T[i][1][0] = max(T[i-1][1][0], T[i-1][1][1] + prices[i]);
		T[i][1][1] = max(T[i-1][1][1], T[i-1][0][0] - prices[i]);
		T[i][2][0] = max(T[i-1][2][0], T[i-1][2][1] + prices[i]);
		T[i][2][1] = max(T[i-1][2][1], T[i-1][1][0] - prices[i]);
	}

	return T[n-1][2][0];
}

// Helper functions
func max(a int, b int) int {
	if a > b {
		return a;
	}
	return b;
}