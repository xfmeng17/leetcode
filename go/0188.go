func maxProfit(k int, prices []int) int {
    return func1(k, prices);
}

/*
 * The series-of-stock problems
 * T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
 * T[i][k][1] = max(T[i-1][1], T[i-1][k-1][0] - prices[i])
 */

const INT_MAX = int(^uint(0) >> 1);
const INT_MIN = ^INT_MAX;

func func1(k int, prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}
	/*
	 * If k >= len(prices) / 2, k is same as +INF
	 * Use k_is_inf() function (The solution in 0122.go) to avoid leetcode
	 * oj stack-overflow beacuse I will make a [n][k][2]int array.
	 */
	if k >= len(prices) / 2 {
		return k_is_inf(prices);
	}

	n := len(prices);
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
	for j := 1; j <= k; j++ {
		T[0][j][0] = 0;
		T[0][j][1] = 0 - prices[0];
	}

	for i := 1; i < n; i++ {
		T[i][0][0] = 0;
		T[i][0][1] = INT_MIN;
		for j := 1; j <= k; j++ {
			T[i][j][0] = max(T[i-1][j][0], T[i-1][j][1] + prices[i]);
			T[i][j][1] = max(T[i-1][j][1], T[i-1][j-1][0] - prices[i]);
		}
	}

	return T[n-1][k][0];
}

func k_is_inf(prices []int) int {
    if len(prices) <= 0 {
        return 0;
    }
    // Initially, i = -1
    T_ik0 := 0;
    T_ik1 := INT_MIN;

    for i := 0; i < len(prices); i++ {
        T_ik0_aux := T_ik0;
        T_ik0 = max(T_ik0, T_ik1 + prices[i]);
        T_ik1 = max(T_ik1, T_ik0_aux - prices[i]);
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