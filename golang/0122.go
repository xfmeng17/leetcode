func maxProfit(prices []int) int {
    // return func1(prices);
    return func2(prices);
}

func func1(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}

	ret := 0;
	lo, hi := 0, 0;
	for i := 0; i < len(prices); i++ {
		if prices[i] > prices[hi] {
			hi = i;
		} else {
			ret += prices[hi] - prices[lo];
			lo = i;
			hi = i;
		}
	}
	return ret + (prices[hi] - prices[lo]);
}

/* 
 * The series-of-stock-problems, k = +Infinity
 * T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
 * T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])
 * 
 * As limit(k) = +INF => k ~= k-1 => T[i-1][k-1][0] = T[i-1][k][0]:
 * T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])
 * T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i])
 *
 * The way I think about it is that when you can make as many transcation as
 * you want, k is no longer a constraint here, therefore you can just take [k]
 * and [k-1] out of the equation and let it be constrained by the size of the
 * prices array.
 *
 * T_ik0_aux is unnecessary:
 * 1. T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])
 * 2. T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i])
 * 3. T[i][1] = max(T[i-1][1], T[i][0]   - prices[i])
 * For both condition in 1, ALWAYS get same 2 and 3
 */
const INT_MAX = int(^uint(0) >> 1);
const INT_MIN = ^INT_MAX;

func func2(prices []int) int {
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