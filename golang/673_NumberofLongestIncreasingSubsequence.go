func findNumberOfLIS(nums []int) int {
    return func1(nums);
}

func func1(nums []int) int {
	n := len(nums);
	length := make([]int, n);
	count := make([]int, n);

	for i := 0; i < n; i++ {
		length[i] = 1;
		count[i] = 1;
	}

	maxLen := 1;
	for i := n-1; i >= 0; i-- {
		for j := i+1; j < n; j++ {
			if nums[i] < nums[j] {
				if length[j]+1 > length[i] {
					length[i] = length[j]+1;
					count[i] = count[j];
				} else if length[j]+1 == length[i] {
					count[i] += count[j];
				}
			}
		}
		// fmt.Printf("i=%d, length=%d, count=%d\n", i, length[i], count[i]);
		if length[i] > maxLen {
			maxLen = length[i];
		}
	}

	ret := 0;
	for i := 0; i < n; i++ {
		if length[i] == maxLen {
			ret += count[i];
		}
	}

	return ret;
}