/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

class NumMatrix {

public:
	vector<vector<int>> sum;

public:
    NumMatrix(vector<vector<int>> matrix) {
    	sum = matrix;
    	int m = matrix.size();
    	int n = m > 0 ? matrix[0].size() : 0;

    	for (int i = 0; i < m; i++) {
    		for (int j = 1; j < n; j++) {
    			sum[i][j] += sum[i][j-1];
    		}
    	}
    	for (int i = 1; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			sum[i][j] += sum[i-1][j];
    		}
    	}

    	// for (int i = 0; i < m; i++) {
    	// 	for (int j = 0; j < n; j++) {
    	// 		cout << sum[i][j] << " ";
    	// 	}
    	// 	cout << endl;
    	// }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int d3 = sum[row2][col2];
        int d2 = col1 - 1 >= 0 ? sum[row2][col1-1] : 0;
        int d1 = row1 - 1 >= 0 ? sum[row1-1][col2] : 0;
        int d0 = row1 - 1 >= 0 && col1 - 1 >= 0 ? sum[row1-1][col1-1] : 0;
        return d3 - d2 - d1 + d0;
    }
};

