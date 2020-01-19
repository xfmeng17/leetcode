func lengthOfLIS(nums []int) int {
	// return func1(nums);
	// return func2(nums);
	return func3(nums);
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

//** standard dp
func func2(nums []int) int {
	n := len(nums);
	memo := make([]int, n);
	for i := 0; i < n; i++ {
		memo[i] = 1;
	}
	ret := 0;

	for i := n-1; i >= 0; i-- {
		for j := i+1; j < n; j++ {
			if nums[i] < nums[j] {
				memo[i] = max(memo[i], memo[j] + 1);
			}
		}
		ret = max(ret, memo[i]);
	}

	return ret;
}

//** O(nlogn) binary-search solution, interesting
func func3(nums []int) int {
	n := len(nums);
	arr := make([]int, 0);

	for i := n-1; i >= 0; i-- {
		idx := findLargestLessOrEqualThanTarget(arr, nums[i]);
		if idx >= len(arr) {
			arr = append(arr, nums[i])
		} else {
			arr[idx] = nums[i];
		}
	}

	return len(arr);
}

/* 
 * nums is inverted order and return the index that nums[index] is the
 * largest element <= target
 * eg: [19,18,17,16,10], find target | nums[lo] | nums[hi] | ret:
 * 20 | nums[0]=19 | nums[-1]=  | 0
 * 19 | nums[0]=19 | nums[0]=19 | 0
 * 12 | nums[4]=10 | nums[3]=16 | 4
 * 09 | nums[5]=   | nums[4]=10 | 5
 */
func findLargestLessOrEqualThanTarget(nums []int, target int) int {
	lo := 0;
	hi := len(nums) - 1;

	for (lo <= hi) {
		mid := (lo + hi) / 2;
		if nums[mid] == target {
			return mid;
		} else if nums[mid] > target {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	return lo;
}
