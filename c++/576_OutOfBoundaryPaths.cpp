class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
    	return func1(m, n, N, i, j);
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
};
