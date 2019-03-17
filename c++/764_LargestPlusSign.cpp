class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    	return func1(N, mines);        
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
};
