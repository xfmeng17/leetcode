class Solution {
public:
    int uniquePaths(int m, int n) {
        return func1(m, n);
    }

    // ** recursive + memoization
    int func1(int m, int n) {
    	vector<vector<int>> memo(m, vector<int>(n, 0));
    	return helper1(m, n, 0, 0, memo);
    }
    int helper1(int m, int n, int r, int c,
    	vector<vector<int>>& memo) {

    	if (r < 0 || r >= m) {
    		return 0;
    	}
    	if (c < 0 || c >= n) {
    		return 0;
    	}
    	if (r == m - 1 && c == n - 1) {
    		return 1;
    	}

    	if (memo[r][c] > 0) {
    		return memo[r][c];
    	}

    	memo[r][c] = 0;
    	memo[r][c] += helper1(m, n, r, c+1, memo);
    	memo[r][c] += helper1(m ,n, r+1, c, memo);

    	return memo[r][c];
    }
};
