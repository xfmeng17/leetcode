class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
    	return func1(A);
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
};
