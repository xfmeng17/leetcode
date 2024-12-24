func rob(nums []int) int {
    return func1(nums);
}

func func1(nums []int) int {
    if len(nums) <= 0 {
        return 0;
    }
    if len(nums) == 1 {
        return nums[0];
    }
    if len(nums) == 2 {
        return max(nums[0], nums[1]);
    }
    
    n := len(nums);
    dp := make([]int, n);
    dp[0] = max(0, nums[0]);
    dp[1] = max(dp[0], nums[1]);
    ret := max(0, max(dp[0], dp[1]));
    
    for i := 2; i < n; i++ {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        ret = max(ret, dp[i]);
    }
    
    return ret;
}

func max(a int, b int) int {
    if (a > b) {
        return a;
    }
    return b;
}