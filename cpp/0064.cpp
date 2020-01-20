class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    // return func1(grid);
    // return func2(grid);
    return func3(grid);
  }
  // ** top-down recursion
  // ** of cause, time-limit-exceeded
  int func1(vector<vector<int>> &grid) {
    int height = grid.size();
    if (height <= 0) {
      return 0;
    }
    int weight = grid[0].size();
    if (weight <= 0) {
      return 0;
    }

    int dummySum = 0;
    for (int j = 0; j < weight; j++) {
      dummySum += grid[0][j];
    }
    for (int i = 1; i < height; i++) {
      dummySum += grid[i][weight - 1];
    }

    return min(dummySum, helper1(grid, height, weight, 0, 0, dummySum));
  }
  int helper1(vector<vector<int>> &grid, int ht, int wt, int i, int j,
              int dsum) {

    if (i == ht - 1 && j == wt - 1) {
      return grid[i][j];
    }
    if (i >= ht || j >= wt) {
      return dsum;
    }

    int right = grid[i][j] + helper1(grid, ht, wt, i + 1, j, dsum);
    int down = grid[i][j] + helper1(grid, ht, wt, i, j + 1, dsum);

    return min(right, down);
  }

  // ** recursion with memo
  int func2(vector<vector<int>> &grid) {
    int height = grid.size();
    if (height <= 0) {
      return 0;
    }
    int weight = grid[0].size();
    if (weight <= 0) {
      return 0;
    }

    int dummySum = 0;
    for (int j = 0; j < weight; j++) {
      dummySum += grid[0][j];
    }
    for (int i = 1; i < height; i++) {
      dummySum += grid[i][weight - 1];
    }
    vector<vector<int>> memo(height, vector<int>(weight, 0));

    return min(dummySum, helper2(grid, height, weight, 0, 0, memo, dummySum));
  }
  int helper2(vector<vector<int>> &grid, int ht, int wt, int i, int j,
              vector<vector<int>> &memo, int dsum) {

    if (i == ht - 1 && j == wt - 1) {
      return grid[i][j];
    }
    if (i >= ht || j >= wt) {
      return dsum;
    }
    if (memo[i][j]) {
      return memo[i][j];
    }

    int right = grid[i][j] + helper2(grid, ht, wt, i + 1, j, memo, dsum);
    int down = grid[i][j] + helper2(grid, ht, wt, i, j + 1, memo, dsum);

    memo[i][j] = min(right, down);
    return memo[i][j];
  }

  // ** real buttom-up dp
  int func3(vector<vector<int>> &grid) {
    int height = grid.size();
    if (height <= 0) {
      return 0;
    }
    int weight = grid[0].size();
    if (weight <= 0) {
      return 0;
    }

    vector<int> dp(weight + 1, 0);
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < weight; j++) {
        if (i == 0 && j == 0) {
          dp[j + 1] = grid[i][j];
        } else if (i == 0) {
          dp[j + 1] = grid[i][j] + dp[j];
        } else if (j == 0) {
          dp[j + 1] = grid[i][j] + dp[j + 1];
        } else {
          dp[j + 1] = grid[i][j] + min(dp[j], dp[j + 1]);
        }
      }
    }

    return dp[weight];
  }
};
