func findMaxForm(strs []string, m int, n int) int {
	// return func1(strs, m, n);
	return func2(strs, m, n);
}

// O(len*m*n) time, 2*O(m*n) space
func func1(strs []string, m int, n int) int {
	dp1 := make([][]int, m+1);
	dp2 := make([][]int, m+1);
	for i := 0; i < m+1; i++ {
		dp1[i] = make([]int, n+1);
		dp2[i] = make([]int, n+1);
	}

	for i := 1; i <= len(strs); i++ {
		cnt0, cnt1 := count01(strs[i-1]);
		for j0 := cnt0; j0 <= m; j0++ {
			for j1 := cnt1; j1 <= n; j1++ {
				dp2[j0][j1] = max(dp1[j0][j1], 1 + dp1[j0-cnt0][j1-cnt1]);
			}
		}
		for j0 := 0; j0 <= m; j0++ {
			for j1 := 0; j1 <= n; j1++ {
				dp1[j0][j1] = dp2[j0][j1];
			}
		}
	}
	return dp2[m][n];
}

// O(len*m*n) time, O(m*n) space
func func2(strs []string, m int, n int) int {
	dp1 := make([][]int, m+1);
	for i := 0; i < m+1; i++ {
		dp1[i] = make([]int, n+1);
	}

	for i := 1; i <= len(strs); i++ {
		cnt0, cnt1 := count01(strs[i-1]);
		for j0 := m; j0 >= cnt0; j0-- {
			for j1 := n; j1 >= cnt1; j1-- {
				dp1[j0][j1] = max(dp1[j0][j1], 1 + dp1[j0-cnt0][j1-cnt1]);
			}
		}
	}
	return dp1[m][n];
}

func count01(str string) (int, int) {
	cnt0 := 0;
	cnt1 := 0;
	for _, s := range str {
		if s == '0' {
			cnt0++;
		}
		if s == '1' {
			cnt1++;
		}
	}
	return cnt0, cnt1;
}
func max(a int, b int) int {
	if a > b {
		return a;
	}
	return b;
}
