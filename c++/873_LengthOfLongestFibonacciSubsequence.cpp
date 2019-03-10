class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	// return func1(A);
    	// return func2(A);
    	return func3(A);
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
    // ** can't figure out, I give it up 0.0
    int func2(vector<int>& A) {
    	return 0;
    }

    // ** LCS between origin input and fibonacii sequence
    // ** Totally wrong, cause [1, 3, 5] is not fibonacii-like,
    // ** but it is a subsequence of [1,2,3,5,8...].
    // ** Formula should be: subsequence of origin array, 
    // ** but substring of fabonacii arry.
    int func3(vector<int>& A) {
    	if (A.size() <= 2) {
    		return 0;
    	}
    	// ** init fabonacii sequence
    	vector<int> fabo;
    	fabo.push_back(1);
    	fabo.push_back(2);
    	while (fabo.back() <= A.back()) {
    		int i = fabo.size() - 1;
    		fabo.push_back(fabo[i-1] + fabo[i]);
    	}

    	// ** get LCS
    	int maxLen = 0;
    	vector<int> dp(fabo.size() + 1, 0);
    	for (int i = 1; i <= A.size(); i++) {
    		int pre = 0;
    		for (int j = 1; j <= fabo.size(); j++) {
    			int aux = dp[j];
    			if (A[i-1] == fabo[j-1]) {
    				dp[j] = pre + 1;
    			} else {
    				dp[j] = max(dp[j-1], dp[j]);
    			}
    			pre = aux;
    			if (dp[j] > maxLen) maxLen = dp[j];
    		}
    	}

    	return maxLen;
    }
};
