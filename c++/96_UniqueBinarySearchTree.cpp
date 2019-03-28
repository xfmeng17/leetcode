class Solution {
public:
    int numTrees(int n) {
    	return func1(n);
    }

    // ** recursive + memoization
    int func1(int n) {
    	vector<vector<int>> memo(n+1, vector<int>(n+1, 0));
    	return helper1(1, n, memo);
    }
    int helper1(int lo, int hi, vector<vector<int>>& memo) {
    	if (lo >= hi) return 1;
    	// if (lo == hi) return 1;

    	memo[lo][hi] = 0;
    	for (int mid = lo; mid <= hi; mid++) {
    		memo[lo][hi] += helper1(lo, mid-1, memo) * helper1(mid+1, hi, memo);
    	}

    	return memo[lo][hi];
    }

};
