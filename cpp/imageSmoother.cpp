class Solution {
public:
  // vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
  //     vector<vector<int>> ans(M);
  //     for (int i = 0; i < M.size(); i++) {
  //     	for (int j = 0; j < M[i].size(); j++) {
  //             int cells = 1;
  //     		int sum = M[i][j];
  //     		if (i - 1 >= 0) {
  //     			sum += M[i - 1][j];
  //                 cells++;
  //     			if (j - 1 >= 0) {
  //                     sum += M[i - 1][j - 1];
  //                     cells++;
  //                 }
  //     			if (j + 1 < M[i].size()) {
  //                     sum += M[i - 1][j + 1];
  //                     cells++;
  //                 }
  //     		}
  //     		if (i + 1 < M.size()) {
  //     			sum += M[i + 1][j];
  //                 cells++;
  //     			if (j - 1 >= 0) {
  //                     sum += M[i + 1][j - 1];
  //                     cells++;
  //                 }
  //     			if (j + 1 < M[i].size()) {
  //                     sum += M[i + 1][j + 1];
  //                     cells++;
  //                 }
  //     		}
  //     		if (j - 1 >= 0) {
  //     			sum += M[i][j - 1];
  //                 cells++;
  //     		}
  //     		if (j + 1 < M[i].size()) {
  //     			sum += M[i][j + 1];
  //                 cells++;
  //     		}
  //     		ans[i][j] = sum / cells;
  //     	}
  //     }
  //     return ans;
  // }

  vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    vector<vector<int>> ans(M.size());
    for (int i = 0; i < M.size(); i++) {
      // ans[i] = vector<int>(M[i].size());
      vector<int> row(M[i].size());
      for (int j = 0; j < M[i].size(); j++) {
        int cells = 1;
        int sum = M[i][j];
        if (i - 1 >= 0) {
          sum += M[i - 1][j];
          cells++;
          if (j - 1 >= 0) {
            sum += M[i - 1][j - 1];
            cells++;
          }
          if (j + 1 < M[i].size()) {
            sum += M[i - 1][j + 1];
            cells++;
          }
        }
        if (i + 1 < M.size()) {
          sum += M[i + 1][j];
          cells++;
          if (j - 1 >= 0) {
            sum += M[i + 1][j - 1];
            cells++;
          }
          if (j + 1 < M[i].size()) {
            sum += M[i + 1][j + 1];
            cells++;
          }
        }
        if (j - 1 >= 0) {
          sum += M[i][j - 1];
          cells++;
        }
        if (j + 1 < M[i].size()) {
          sum += M[i][j + 1];
          cells++;
        }
        // ans[i].push_back(sum / cells);
        // ans[i][j] = sum / cells;
        row[j] = sum / cells;
      }
      ans[i] = row;
    }
    return ans;
  }
};

// Did some test for vector init with size
// The vector will fill with default type_value in number of size
