func coinChange(coins []int, amount int) int {
	// return func1(coins, amount);
	// return func2(coins, amount);
	// return completeKnapsack4(coins, amount);
	// return completeKnapsack5(coins, amount);
	return completeKnapsack6(coins, amount);
}

// 1. Basic, Time Limit Exceeded
func func1(coins []int, amount int) int {
	if amount == 0 {
		return 0;
	}

	ret := -1;

	for _, coin := range coins {
		if coin == amount {
			return 1;
		}
		if coin < amount {
			tmp := func1(coins, amount - coin);
			if tmp != -1 {
				if ret == -1 {
					ret = 1 + tmp;
				} else if ret > tmp + 1 {
					ret = tmp + 1;
				}
			}
		}
	}

	return ret;
}

// 2. Top-down memo, Time Limit Exceeded
func func2(coins []int, amount int) int {
	memo := make(map[int]int);
	return helper2(coins, amount, memo);
}
func helper2(coins []int, amount int, memo map[int]int) int {
	if amount == 0 {
		return 0;
	}

	if val, ok := memo[amount]; ok {
		return val;
	}

	ret := -1;
	for _, coin := range coins {
		if coin == amount {
			ret = 1;
			break;
		}
		if coin < amount {
			tmp := helper2(coins, amount - coin, memo);
			if tmp != -1 {
				if ret == -1 {
					ret = 1 + tmp;
				} else if ret > tmp + 1 {
					ret = tmp + 1;
				}
			}
		}
	}
	memo[amount] = ret;

	return memo[amount];
}

// 3. Bottom-up??

// 4. Complete knapsack, 2D array, -1 as failed condition => complex checking
func completeKnapsack4(coins []int, amount int) int {
	if amount == 0 {
		return 0;
	}

	N := len(coins);
	V := amount;

	pack := make([][]int, N+1);
	for i := 0; i < N+1; i++ {
		pack[i] = make([]int, V+1);
		for j := 0; j < V+1; j++ {
			pack[i][j] = -1;
		}
	}
	for i := 0; i < N+1; i++ {
		pack[i][0] = 0;
	}

	for i := 1; i <= N; i++ { 
		for v := 0; v <= V; v++ {
			if pack[i-1][v] != -1 {
				pack[i][v] = pack[i-1][v];
			}
			if v >= coins[i-1] && pack[i][v-coins[i-1]] != -1 {
				if pack[i][v] == -1 {
					pack[i][v] = pack[i][v-coins[i-1]] + 1;
				} else {
					pack[i][v] = min(pack[i][v], pack[i][v-coins[i-1]] + 1);
				}
			}
		}
	}

	ret := -1;
	for i := 1; i <= N; i++ {
		if pack[i][V] != -1 {
			if ret == -1 {
				ret = pack[i][V];
			} else {
				ret = min(ret, pack[i][V]);
			}
		}
	}

	return ret;
}

// 5. Complete knapsack, 2D array, amount + 1 as failed condition => simple checking
// !!!Key Point, set ret = amount + 1,
// because max number of operations is put 1 into package with amount time
func completeKnapsack5(coins []int, amount int) int {
	if amount == 0 {
		return 0;
	}

	N := len(coins);
	V := amount;

	pack := make([][]int, N+1);
	for i := 0; i < N+1; i++ {
		pack[i] = make([]int, V+1);
		for j := 0; j < V+1; j++ {
			pack[i][j] = amount + 1;
		}
	}
	for i := 0; i < N+1; i++ {
		pack[i][0] = 0;
	}

	for i := 1; i <= N; i++ { 
		for v := 0; v <= V; v++ {
			pack[i][v] = pack[i-1][v];
			if v >= coins[i-1] {
				pack[i][v] = min(pack[i][v], pack[i][v-coins[i-1]] + 1);
			}
		}
	}

	ret := amount + 1;
	for i := 1; i <= N; i++ {
		ret = min(ret, pack[i][V]);
	}
	if ret == amount + 1 {
		return -1;
	}

	return ret;
}

// 6. Complete knapsack, 1D array
func completeKnapsack6(coins []int, amount int) int {
	if amount == 0 {
		return 0;
	}

	N := len(coins);
	V := amount;

	pack := make([]int, V+1);
	for i := 1; i < V+1; i++ {
		pack[i] = amount + 1;
	}

	for i := 1; i <= N; i++ { 
		for v := 0; v <= V; v++ {
			if v >= coins[i-1] {
				pack[v] = min(pack[v], pack[v-coins[i-1]] + 1);
			}
		}
	}

	if pack[V] == amount + 1 {
		return -1;
	}

	return pack[V];
}

func min(a int, b int) int {
	if a < b {
		return a;
	}
	return b;
}