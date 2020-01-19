func uniquePaths(m int, n int) int {
	// return func1(m-1, n-1, 0, 0);
	// return func2(m, n);
	return func4(m, n);
}

//  1. recursive
func func1(m int, n int, i int, j int) int {
	if i < 0 || m < i || j < 0 || n < j {
		return 0;
	}
	if m == i && n == j {
		return 1;
	}

	return func1(m, n, i+1, j) + func1(m, n, i, j+1);
}

//  2. recursive + memo
func func2(m int, n int) int {
	memo := make([][]int, m);
	for i := 0; i < m; i++ {
		memo[i] = make([]int, n);
		for j := 0; j < n; j++ {
			memo[i][j] = -1;
		}
	}

	return helper2(m-1, n-1, 0, 0, memo);

}
func helper2(m int, n int, i int, j int, memo [][]int) int {
	if i < 0 || m < i || j < 0 || n < j {
		return 0;
	}
	if m == i && n == j {
		return 1;
	}

	if memo[i][j] != -1 {
		return memo[i][j];
	}
	
	memo[i][j] = helper2(m, n, i+1, j, memo) + helper2(m, n, i, j+1, memo);
	return memo[i][j];
}

//  3. iterative + memo, pass
//  4. iterative + 2N variables
func func4(m int, n int) int {
	memo := make([][]int, 2);
	for i := 0; i < 2; i++ {
		memo[i] = make([]int, n);
		for j := 0; j < n; j++ {
			memo[i][j] = 0;
		}
	}
	memo[(m-1)%2][n-1] = 1;

	for i := m-1; i >= 0; i-- {
		for j := n-1; j >= 0; j-- {
			if i == m-1 && j == n-1 {
				continue;
			}
			memo[i%2][j] = 0;
			if j+1 < n {
				memo[i%2][j] += memo[i%2][j+1];
			}
			if i+1 < m {
				memo[i%2][j] += memo[(i+1)%2][j];
			}
		}
	}
	// for i := 0; i < 2; i++ {
	// 	for j := 0; j < n; j++ {
	// 		fmt.Println(i, j, memo[i][j]);
	// 	}
	// }
	return memo[0][0];
}