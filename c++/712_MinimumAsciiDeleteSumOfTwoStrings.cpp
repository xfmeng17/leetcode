class Solution {
public:
	const int UP_LEFT = 1;
	const int UP = 2;
	const int LEFT = 3;

    int minimumDeleteSum(string s1, string s2) {  
    	return func1(s1, s2);      
    }
    // ** LCS with a extra trace table named 'b'
    // ** O(m*n) space and Memory Limit Exceeded

    int func1(string s1, string s2) {
    	int m = s1.length();
    	int n = s2.length();
    	vector<vector<int>> c(m + 1);
    	vector<vector<int>> b(m + 1);
    	for (int i = 0; i <= m; i++) {
    		c[i].resize(n + 1);
    		b[i].resize(n + 1);
    	}

    	for (int i = 0; i <= m; i++) {
    		c[i][0] = 0;
    	}
    	for (int i = 0; i <=n; i++) {
    		c[0][i] = 0;
    	}
    	for (int i = 1; i <= m; i++) {
    		for (int j = 1; j <= n; j++) {
    			if (s1[i-1] == s2[j-1]) {
    				c[i][j] = c[i-1][j-1] + 1;
    				b[i][j] = UP_LEFT;
    			} else if (c[i-1][j] >= c[i][j-1]) {
    				c[i][j] = c[i-1][j];
    				b[i][j] = UP;
    			} else {
    				c[i][j] = c[i][j-1];
    				b[i][j] = LEFT;
    			}
    		}
    	}
    	int s1AsciiSum = 0;
    	for (int i = 0; i < m; i++) {
    		s1AsciiSum += s1[i];
    	}
    	int s2AsciiSum = 0;
    	for (int i = 0; i < n; i++) {
    		s2AsciiSum += s2[i];
    	}
    	// ** 2
    	return s1AsciiSum + s2AsciiSum - maxPathAsciiSum(c, b, m, n, s1, s2);
    	// ** 1
    	/*
    	int maxRemainSum = 0;
    	for (int col = n; col >= 1; col--) {
    		if (c[m][col] != c[m][n]) {
    			break;
    		}
    		int i = m;
    		int j = col;
    		int remainSum = 0;
    		while (c[i][j] > 0) {
    			if (b[i][j] == UP_LEFT) {
    				remainSum += s1[i-1];
    				remainSum += s2[j-1];
    				i--;
    				j--;
    			} else if (b[i][j] == UP) {
    				i--;
    			} else {
    				j--;
    			}
    		}
			maxRemainSum = max(maxRemainSum, remainSum);
			cout << "col =" << col << " maxRemainSum = " << maxRemainSum << endl;
    	}
    	return s1AsciiSum + s2AsciiSum - maxRemainSum;
    	*/
    }
    int maxPathAsciiSum(vector<vector<int>>& c, vector<vector<int>>& b, int i, int j, string s1, string s2) {
    	if (i <= 0 || j <= 0) {
    		return 0;
    	}
    	if (c[i][j] == 0) {
    		return 0;
    	}

    	int upLeft = 0;
    	if (b[i][j] == UP_LEFT) {
    		upLeft = s1[i-1] + s2[j-1] + maxPathAsciiSum(c, b, i-1, j-1, s1, s2);
    	}

    	int up = 0;
    	if (c[i-1][j] == c[i][j]) {
    		up = maxPathAsciiSum(c, b, i-1, j, s1, s2);
    	}
    	int left = 0;
    	if (c[i][j-1] == c[i][j]) {
    		left = maxPathAsciiSum(c, b, i, j-1, s1, s2);
    	}
    	return max(max(upLeft, up), left);
    }

};
