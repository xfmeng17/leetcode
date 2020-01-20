func coinChange(coins []int, amount int) int {
	// return func1(coins, amount);
	return func2(coins, amount);
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