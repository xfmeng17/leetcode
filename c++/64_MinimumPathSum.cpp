class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return func1(grid);        
    }
    // ** top-down recursion
    // ** of cause, time-limit-exceeded
    int func1(vector<vector<int>>& grid) {
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
            dummySum += grid[i][weight-1];
        }

        return min(dummySum, helper1(grid, height, weight, 0, 0, dummySum));
    }
    int helper1(vector<vector<int>>& grid,
        int ht, int wt, int i, int j, int dsum) {
        
        if (i == ht - 1 && j == wt - 1) {
            return grid[i][j];
        }
        if (i >= ht || j >= wt) {
            return dsum;
        }

        int right = grid[i][j] + helper1(grid, ht, wt, i+1, j, dsum);
        int down = grid[i][j] + helper1(grid, ht, wt, i, j+1, dsum);

        return min(right, down);
    }
};
