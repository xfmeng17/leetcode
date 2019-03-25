class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
    	// return func1(A);
    	// return func2(A);
    	return func3(A);
    }

    /* dp[i][j] stores result of A[i..j]
	 * dp[i][j] = dp[i][j-1] | A[j]
	 * use a extra hashset to mark
	 * TLE
    */
    int func1(vector<int>& A) {
    	int N = A.size();
    	vector<vector<int>> dp(N, vector<int>(N, 0));
    	unordered_set<int> table;

    	for (int i = 0; i < N; i++) {
    		for (int j = i; j < N; j++) {
    			if (i == j) {
    				dp[i][j] = A[i];
    			} else {
    				dp[i][j] = dp[i][j-1] | A[j];
    			}
    			if (table.count(dp[i][j]) <= 0) {
    				table.insert(dp[i][j]);
    			}
    		}
    	}

    	return table.size();
    }

    // ** more concise
    int func2(vector<int>& A) {
    	int N = A.size();
    	unordered_set<int> table;

    	for (int i = 0; i < N; i++) {
    		int cur = A[i];
    		for (int j = i; j < N; j++) {
    			cur |= A[j];
    			if (table.count(cur) <= 0) {
    				table.insert(cur);
    			}
    		}
    	}

    	return table.size();
    }
 	
 	/* Reference:
 	 * Time complexity reduce to O(30N).
 	 * There are at most 30 bits for a positive number 0 <= A[i] <= 10^9.
 	 * So there are at most 30 different values in "cur".
 	 * 
 	 * Impressive time optimized design
 	*/
 	int func3(vector<int>& A) {
 		int N = A.size();
 		unordered_set<int> res;
 		unordered_set<int> pre;

 		for (int i = 0; i < N; i++) {
 			unordered_set<int> cur;
 			cur.insert(A[i]);
 			for (auto p : pre) {
 				cur.insert(p | A[i]);
 			}
 			pre = cur;
 			res.insert(pre.begin(), pre.end());
 		}

 		return res.size();
 	}
};
