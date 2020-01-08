func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m := len(obstacleGrid)
	n := len(obstacleGrid[0])
	return func4(obstacleGrid, m, n)
}

//** 3. iterative + memo, pass
//** 4. iterative + 2N variables
func func4(obstacleGrid [][]int, m int, n int) int {
	memo := make([][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = make([]int, n)
		for j := 0; j < n; j++ {
			memo[i][j] = 0
		}
	}

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			if i == m-1 && j == n-1 {
				if obstacleGrid[m-1][n-1] == 1 {
					memo[(m-1)%2][n-1] = 0
				} else {
					memo[(m-1)%2][n-1] = 1
				}
				continue
			}

			memo[i%2][j] = 0
			if obstacleGrid[i][j] == 1 {
				continue
			}
			if j+1 < n {
				memo[i%2][j] += memo[i%2][j+1]
			}
			if i+1 < m {
				memo[i%2][j] += memo[(i+1)%2][j]
			}
		}
	}
	return memo[0][0]
}