func combinationSum4(nums []int, target int) int {
	// return func1(nums, target);
	return func2(nums, target);
}

// 1. complete-knapsack-problm
// !! ERROR, Can't use CKP
func func1(nums []int, target int) int {
	N := len(nums);
	if N <= 0 || target < 0 {
		return 0;
	}

	pack := make([]int, target+1);
	pack[0] = 1;

	for i := 0; i < N; i++ {
		for v := 0; v <= target; v++ {
			if v >= nums[i] {
				pack[v] = max(pack[v], 1 + pack[v-nums[i]]);
			}
		}
	}

	return pack[target];
}

// 2. standard DP, dp[n] means combinations to n
// O(n^2) time
func func2(nums []int, target int) int {
	dp := make([]int, target+1);
	dp[0] = 1;
	for i := 1; i <= target; i++ {
		for _, n := range nums {
			if i >= n {
				dp[i] += dp[i-n];
			}
		}
	}
	return dp[target];
}

func max(a int, b int) int {
	if a > b {
		return a;
	}
	return b;
}