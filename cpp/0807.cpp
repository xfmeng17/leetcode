class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    return func1(grid);
  }

  int func1(vector<vector<int>> &grid) {
    int res = 0;
    if (grid.size() <= 0) {
      return res;
    }

    vector<int> row(grid.size());
    vector<int> col(grid[0].size());

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] > row[i]) {
          row[i] = grid[i][j];
        }
        if (grid[i][j] > col[j]) {
          col[j] = grid[i][j];
        }
      }
    }
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        res += min(row[i], col[j]) - grid[i][j];
      }
    }

    return res;
  }
};
