class NumMatrix {

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
public:
	vector<vector<int>> mat;
	unordered_map<string, int> res;
	const char SP = '|';

public:
    NumMatrix(vector<vector<int>> matrix) {
		mat = matrix;
		res.clear();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    	string s = to_string(row1) + SP + to_string(col1) + SP + to_string(row2) + SP + to_string(col2);
    	auto it = res.find(s);
    	if (it != res.end()) {
    		return it->second;
    	}

    	int sum = 0;
    	for (int i = row1; i <= row2; i++) {
    		for (int j = col1; j <= col2; j++) {
    			sum += mat[i][j];
    		}
    	}
    	res[s] = sum;
    	return sum;
    }
};
