func canPartition(nums []int) bool {
	// return func1(nums);
	return func2(nums);
}

/* pack[i][v] means:
 * 1. The i-th item, weight=nums[i-1]
 * 2. The v capacity package
 */
func func1(nums []int) bool {
	sum := 0;
	for i := 0; i < len(nums); i++ {
		sum += nums[i];
	}
	if sum % 2 != 0 {
		return false;
	}

	vol := sum / 2;
	N := len(nums);

	pack := make([][]bool, N + 1);
	for i := 0; i <= N; i++ {
		pack[i] = make([]bool, vol + 1);
	}
	pack[0][0] = true;

	for i := 1; i <= N; i++ {
		curr_v := nums[i-1];
		for v := vol; v >= 0; v-- {
			if v >= curr_v {
				pack[i][v] = pack[i-1][v] || pack[i-1][v-curr_v];
			} else {
				pack[i][v] = pack[i-1][v];
			}
		}
	}

	for i := 0; i <= N; i++ {
		if pack[i][vol] == true {
			return true
		}
	}
	return false
}

func func2(nums []int) bool {
	sum := 0;
	for i := 0; i < len(nums); i++ {
		sum += nums[i];
	}
	if sum % 2 != 0 {
		return false;
	}

	vol := sum / 2;
	N := len(nums);

	pack := make([]bool, vol + 1);
	pack[0] = true;

	for i := 1; i <= N; i++ {
		curr_v := nums[i-1];
		for v := vol; v >= 0; v-- {
			if v >= curr_v {
				pack[v] = pack[v] || pack[v-curr_v];
			} else {
				pack[v] = pack[v];
			}
		}
		if pack[vol] == true {
			return true;
		}
	}

	return false
}
