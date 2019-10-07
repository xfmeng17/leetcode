class Solution {
public:
	const int MOD = 1e9 + 7;
public:
    int findPaths(int m, int n, int N, int i, int j) {
    	// return func1(m, n, N, i, j);
    	// return func2(m, n, N, i, j);
    	return func3(m, n, N, i, j);
    }

    int func1(int m, int n, int N, int i, int j) {
    	if (i < 0 || i >= m) {
    		return 1;
    	}
    	if (j < 0 || j >= n) {
    		return 1;
    	}
    	if (N <= 0) {
    		return 0;
    	}
    	int up = func1(m, n, N-1, i-1, j);
    	int down = func1(m, n, N-1, i+1, j);
    	int left = func1(m, n, N-1, i, j-1);
    	int right = func1(m, n, N-1, i, j+1);

    	return up + down + left + right;
    }

    // ** recursive + memoization
    int func2(int m, int n, int N, int i, int j) {
    	vector<vector<vector<int>>> memo(N+1, vector<vector<int>>(m, vector<int>(n, -1)));
    	return helper2(m, n, N, i, j, memo);
    }

    int helper2(int m, int n, int N, int i, int j,
    	vector<vector<vector<int>>>& memo) {

		
		if (i < 0 || i >= m) {
    		return 1;
    	}
    	if (j < 0 || j >= n) {
    		return 1;
    	}
    	if (N <= 0) {
    		return 0;
    	}
    	if (memo[N][i][j] >= 0) {
    		return memo[N][i][j];
    	}

    	int up = helper2(m, n, N-1, i-1, j, memo);
    	int down = helper2(m, n, N-1, i+1, j, memo);
    	int left = helper2(m, n, N-1, i, j-1, memo);
    	int right = helper2(m, n, N-1, i, j+1, memo);

    	memo[N][i][j] = 0;
    	memo[N][i][j] += up;
    	memo[N][i][j] %= MOD;
    	memo[N][i][j] += down;
    	memo[N][i][j] %= MOD;
    	memo[N][i][j] += left;
    	memo[N][i][j] %= MOD;
    	memo[N][i][j] += right;
    	memo[N][i][j] %= MOD;

    	return memo[N][i][j];
    }

    // ** two 2D array bottom-up
    int func3(int m, int n, int N, int i, int j) {
    	vector<vector<int>> dp1(m, vector<int>(n, 0));
    	vector<vector<int>> dp2(m, vector<int>(n, 0));

    	// ** N = 0
    	if (N <= 0) return 0;
    	
    	// ** N = 1 or more
    	for (int k = 1; k <= N; k++) {
    		for (int x = 0; x < m; x++) {
    			for (int y = 0; y < n; y++) {
    				dp1[x][y] = 0;
    				// ** up
    				if (x - 1 >= 0) {
    					dp1[x][y] += dp2[x-1][y];
    				} else {
    					dp1[x][y] += 1;
    				}
    				// ** down
    				if (x + 1 < m) {
    					dp1[x][y] += dp2[x+1][y];
    					dp1[x][y] %= MOD;
    				} else {
    					dp1[x][y] += 1;
    				}
    				// ** left
    				if (y - 1 >= 0) {
    					dp1[x][y] += dp2[x][y-1];
    					dp1[x][y] %= MOD;
    				} else {
    					dp1[x][y] += 1;
    				}
    				// ** right
    				if (y + 1 < n) {
    					dp1[x][y] += dp2[x][y+1];
    					dp1[x][y] %= MOD;
    				} else {
    					dp1[x][y] += 1;
    				}
    			}
    		}
    		// ** copy dp1 to dp2
    		for (int x = 0; x < m; x++) {
    			for (int y = 0; y < n; y++) {
    				dp2[x][y] = dp1[x][y];
    			}
    		}
    	}

    	return dp1[i][j];
    }
};
