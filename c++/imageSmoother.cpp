class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans(M.size());
        for (int i = 0; i < M.size(); i++) {
        	vector<int> row(M[i].size());
        	for (int j = 0; j < M[i].size(); j++) {
        		int sum = 0;
        		// if (i - 1 >= 0) {
        		// 	sum += M[i - 1][j];
        		// 	if (j - 1 >= 0) sum += M[i + 1][j - 1];
        		// 	if (j + 1 < M[i].size()) sum += M[i - 1][j + 1];
        		// }
        		// if (i + 1 < M.size()) {
        		// 	sum += M[i + 1][j];
        		// 	if (j - 1 >= 0) sum += M[i + 1][j - 1];
        		// 	if (j + 1 < M[i].size()) sum += M[i + 1][j + 1];
        		// }
        		// if (j - 1 >= 0) {
        		// 	sum += M[i][j - 1];
        		// 	if (i - 1 >= 0) sum += M[i - 1][j - 1];
        		// 	if (i + 1 < M.size()) sum += M[i + 1][j - 1];
        		// }
        		// if (j + 1 < M[i].size()) {
        		// 	sum += M[i][j + 1];
        		// 	if (i - 1 >= 0) sum += M[i - 1][j + 1];
        		// 	if (i + 1 < M.size()) sum += M[i + 1][j + 1];
        		// }
        		row.push_back(sum / 9);
        	}
        	ans.push_back(row);
        }
        return ans;
    }
};
