class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	// return func1(A);
    	// return func2(A);
    	// return func3(A);
    	// return func4(A);
    	return func5(A);
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
    // ** update 190310, such memoization don't make any effect.
    int func2(vector<int>& A) {
    	vector<vector<int>> memo(A.size()+1, vector<int>(A.size()+1, 0));
    	memo[0][0] = 0;
    	int ret = helper2(A, 1, 0, 0, memo);
    	return ret >= 3 ? ret : 0;
    }
    int helper2(vector<int>& A, int i, int p1, int p2,
    	vector<vector<int>>& memo) {

    	if (i > A.size()) {
    		return 0;
    	}
    	if (memo[p1][p2] > 0) {
    		return memo[p1][p2];
    	}

    	if (p1 == 0 || p2 == 0) {
    		int pick = 1 + helper2(A, i+1, p2, i, memo);
    		memo[p2][i] = pick;
    		int notp = 0 + helper2(A, i+1, p1, p2, memo);
    		return max(pick, notp);
    	}

    	int notp = 0 + helper2(A, i+1, p1, p2, memo);
    	int pick = notp;
    	if (A[p1-1] + A[p2-1] == A[i-1]) {
    		pick = 1 + helper2(A, i+1, p2, i, memo);
    		memo[p2][i] = pick;
    	}

    	return max(pick, notp);
    }

    // ** LCS between origin input and fibonacii sequence
    // ** Totally wrong, cause [1, 3, 5] is not fibonacii-like,
    // ** but it is a subsequence of [1,2,3,5,8...].
    // ** Formula should be: subsequence of origin array, 
    // ** but substring of fabonacii arry.
    // ** Also, as input [1, 11, 12], obviously, has no relation
    // ** with [1,2,3,5,8....]
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
    	for (auto x : dp) {
    		cout << x << endl;
    	}
    	return maxLen;
    }

    // ** "Check Pair" from discuss
    int func4(vector<int>& A) {
    	unordered_set<int> set(A.begin(), A.end());
    	int ret = 0;
    	for (int i = 0; i < A.size(); i++) {
    		for (int j = i+1; j < A.size(); j++) {
    			int a = A[i], b = A[j], len = 2;
    			while (set.count(a+b)) {
    				b = a + b;
    				a = b - a;
    				len++;
    			}
    			ret = max(ret, len);
    		}
    	}
    	return ret > 2 ? ret : 0;
    }

    // ** dp[i, j] meams the maximum length of subsequence
    // ** ends with A[i] and A[j].
    // ** Implement refer to discuss, brilliant code.
    int func5(vector<int>& A) {
    	unordered_map<int, int> map;
    	int n = A.size(), ret = 0;
    	vector<vector<int>> dp(n, vector<int>(n, 0));
    	for (int j = 0; j < n; j++) {
    		map[A[j]] = j;
    		for (int i = 0; i < j; ++i) {
    			int k = map.find(A[j] - A[i]) == map.end() ? -1 : map[A[j] - A[i]];
    			dp[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? dp[k][i] + 1 : 2;
    			ret = max(ret, dp[i][j]);
    		}
    	}
    	return ret > 2 ? ret : 0;
    }
};
