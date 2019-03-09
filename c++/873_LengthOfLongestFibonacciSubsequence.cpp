class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	// return func1(A);
    	return func2(A);
    }

    // ** recursion top-down
    int func1(vector<int>& A) {
    	int ret = helper1(A, 0, 0, 0);

    	return ret >= 3 ? ret : 0;
    }
    int helper1(vector<int>& A, int i, int prev1, int prev2) {
    	if (i >= A.size()) {
    		return 0;
    	}

    	if (prev1 == 0 || prev2 == 0) {
    		int pick = 1 + helper1(A, i+1, prev2, A[i]);
    		int notp = 0 + helper1(A, i+1, prev1, prev2);
    		return max(pick, notp);
    	}

    	int notp = 0 + helper1(A, i+1, prev1, prev2);
    	int pick = notp;
    	if (prev1 + prev2 == A[i]) {
    		pick = 1 + helper1(A, i+1, prev2, A[i]);
    	}

    	return max(pick, notp);
    }

    // ** recursion top-down + memo
    int func2(vector<int>& A) {
    }

};
