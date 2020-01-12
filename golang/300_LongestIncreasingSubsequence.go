func lengthOfLIS(nums []int) int {
    return func1(nums);
}

//** sort + LCS
func func1(nums []int) int {
	if len(nums) <= 0 {
		return 0;
	}

	sorted := make([]int, len(nums));
	for i := 0; i < len(nums); i++ {
		sorted[i] = nums[i];
	}
	sort.Ints(sorted);

	unique := make([]int, 1, len(nums));
	unique[0] = sorted[0];
	for i := 1; i < len(sorted); i++ {
		if sorted[i] != unique[len(unique)-1] {
			unique = append(unique, sorted[i]);
		}
	}

	return lengthOfLCS(unique, nums);
}
func lengthOfLCS(nums1 []int, nums2 []int) int {
	m := len(nums1);
	n := len(nums2);

	ret := 0;
	memo := make([][]int, m+1);
	for i := 0; i < m+1; i++ {
		memo[i] = make([]int, n+1);
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if nums1[i] == nums2[j] {
				memo[i+1][j+1] = memo[i][j] + 1;
			} else {
				memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
			}
			ret = max(ret, memo[i+1][j+1])
		}
	}

	return ret;
}

func max(a int, b int) int {
	if a > b {
		return a;
	} else {
		return b;
	}
}