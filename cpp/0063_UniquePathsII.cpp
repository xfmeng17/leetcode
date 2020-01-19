class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    // return func1(obstacleGrid, 0, 0);
    return func2(obstacleGrid);
  }

  // ** recursive, TLE
  int func1(vector<vector<int>> &grid, int r, int c) {
    if (r >= grid.size()) {
      return 0;
    }
    if (c >= grid[r].size()) {
      return 0;
    }
    if (grid[r][c] == 1) {
      return 0;
    }
    if (r == grid.size() - 1 && c == grid[r].size() - 1) {
      return 1;
    }

    return func1(grid, r + 1, c) + func1(grid, r, c + 1);
  }

  // ** recursive + memoization
  int func2(vector<vector<int>> &grid) {
    int row = grid.size();
    if (row <= 0) {
      return 0;
    }
    int col = grid[0].size();
    if (col <= 0) {
      return 0;
    }
    vector<vector<int>> memo(row, vector<int>(col, -1));
    return helper2(grid, 0, 0, row, col, memo);
  }
  int helper2(vector<vector<int>> &grid, int r, int c, int row, int col,
              vector<vector<int>> &memo) {

    if (r >= row)
      return 0;
    if (c >= col)
      return 0;
    if (grid[r][c] == 1)
      return 0;
    if (r == row - 1 && c == col - 1)
      return 1;
    if (memo[r][c] >= 0)
      return memo[r][c];

    memo[r][c] = 0;
    memo[r][c] += helper2(grid, r + 1, c, row, col, memo);
    memo[r][c] += helper2(grid, r, c + 1, row, col, memo);

    return memo[r][c];
  }
};
