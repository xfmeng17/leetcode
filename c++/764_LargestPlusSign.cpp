class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    	// return func1(N, mines);
    	return func2(N, mines);
    }

    // ** straight forward iterative
    int func1(int N, vector<vector<int>>& mines) {
    	vector<vector<int>> plusSign(N, vector<int>(N, 1));
    	for (int i = 0; i < mines.size(); i++) {
    		plusSign[mines[i][0]][mines[i][1]] = 0;
    	}

    	int n = (N + 1) / 2;
    	while (n > 0) {
    		int len = n - 1;
    		for (int i = len; i + len < N; i++) {
    			for (int j = len; j + len < N; j++) {
    				bool flag = true;
    				for (int k = j - len; k <= j + len && flag; k++) {
    					flag = plusSign[i][k] == 1;
    				}
    				for (int k = i - len; k <= i + len && flag; k++) {
    					flag = plusSign[k][j] == 1;
    				}
    				if (flag) {
    					return n;
    				}
    			}
    		}
    		n--;
    	}

    	return 0;
    }

    // ** 2 array dp, time O(N^3), TLE when N=500
    int func2(int N, vector<vector<int>>& mines) {
    	if (N <= 0) {
    		return 0;
    	}
    	if (N * N <= mines.size()) {
    		return 0;
    	}
    	vector<vector<int>> arr(N, vector<int>(N, 1));
    	vector<vector<int>> dp1(N, vector<int>(N, 1));
    	vector<vector<int>> dp2(N, vector<int>(N, 1));
    	for (auto m : mines) {
    		arr[m[0]][m[1]] = 0;
    		dp1[m[0]][m[1]] = 0;
    		dp2[m[0]][m[1]] = 0;
    	}

		int maxOrder = (N + 1) / 2;
    	for (int n = 1; n <= maxOrder; n++) {
			int space = n - 1;
    		bool sign = false;
    		for (int i = 0; i < N; i++) {
    			for (int j = 0; j < N; j++) {
    				dp1[i][j] = dp2[i][j];
    				if (i - space < 0 || arr[i-space][j] == 0) dp1[i][j] = 0;
    				if (j - space < 0 || arr[i][j-space] == 0) dp1[i][j] = 0;
    				if (i + space >= N || arr[i+space][j] == 0) dp1[i][j] = 0;
    				if (j + space >= N || arr[i][j+space] == 0) dp1[i][j] = 0;

    				if (dp1[i][j] == 1) {
						sign = true;
					}
    			}
    		}
    		if (!sign) {
    			return n - 1;
    		}
    		for (int i = 0; i < N; i++) {
    			for (int j = 0; j < N; j++) {
    				dp2[i][j] = dp1[i][j];
    			}
    		}
    	}

    	return maxOrder;
    }
};
