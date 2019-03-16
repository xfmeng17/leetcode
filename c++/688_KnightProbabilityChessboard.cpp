class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        // return func1(N, K, r, c);
        return func2(N, K, r, c);
    }

    // ** 8-direction recursive
    double func1(int N, int K, int r, int c) {
        double all = pow(8.0, K);
        int res = helper1(N, K, r, c);
        return (0.0 + res) / all;
    }
    int helper1(int N, int K, int r, int c) {
    	if (r < 0 || r >= N || c < 0 || c >= N) {
    		return 0;
    	}
    	if (K == 0) {
			return 1;
    	}

    	int d1 = helper1(N, K-1, r-2, c-1);
    	int d2 = helper1(N, K-1, r-1, c-2);
    	int d3 = helper1(N, K-1, r+1, c-2);
    	int d4 = helper1(N, K-1, r+2, c-1);
    	int d5 = helper1(N, K-1, r+2, c+1);
    	int d6 = helper1(N, K-1, r+1, c+2);
    	int d7 = helper1(N, K-1, r-1, c+2);
    	int d8 = helper1(N, K-1, r-2, c+1);

    	return d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8;
    }

    // ** top-down dp, time O(KN^2)
    double func2(int N, int K, int r, int c) {
    	vector<vector<vector<double>>> dp;
    	for (int i = 0; i <= K; i++) {
    		vector<vector<double>> vec(N, vector<double>(N, -1.0));
    		dp.push_back(vec);
    	}
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < N; j++) {
    			dp[0][i][j] = 1;
    		}
    	}

        double res = helper2(N, K, r, c, dp);
        return res;
    }
    double helper2(int N, int K, int r, int c, 
    	vector<vector<vector<double>>>& dp) {

    	if (r < 0 || r >= N || c < 0 || c >= N) {
    		return 0;
    	}
    	if (K == 0) {
    		return 1;
    	}
    	if (dp[K][r][c] >= 0) {
			return dp[K][r][c];
    	}

    	double d1 = helper2(N, K-1, r-2, c-1, dp);
    	double d2 = helper2(N, K-1, r-1, c-2, dp);
    	double d3 = helper2(N, K-1, r+1, c-2, dp);
    	double d4 = helper2(N, K-1, r+2, c-1, dp);
    	double d5 = helper2(N, K-1, r+2, c+1, dp);
    	double d6 = helper2(N, K-1, r+1, c+2, dp);
    	double d7 = helper2(N, K-1, r-1, c+2, dp);
    	double d8 = helper2(N, K-1, r-2, c+1, dp);
    	dp[K][r][c] = (d1 + d2 + d3 + d4 + d5 + d6 + d7 + d8) / 8.0;

    	return dp[K][r][c];
    }
};
