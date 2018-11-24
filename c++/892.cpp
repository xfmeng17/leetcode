class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        // return func1(grid);
        return func2(grid);
    }

    int func1(vector<vector<int>>& grid) {
        int all = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                all += grid[i][j];
            }
        }
        all = all * 6;

        int self = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                self += grid[i][j] > 0 ? grid[i][j] - 1 : 0;
            }
        }
        self = self * 2;

        int each = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (j + 1 < grid[i].size()) {
                    each += min(grid[i][j], grid[i][j+1]);
                }
                if (i + 1 < grid.size()) {
                    each += min(grid[i][j], grid[i+1][j]);
                }
            }
        }
        each = each * 2;

        return all - self -each;
    }

    // ** like func1 just put all test in one for
    int func2(vector<vector<int>>& grid) {
        int all = 0;
        int self = 0;
        int each = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                all += grid[i][j];
                self += grid[i][j] > 0 ? grid[i][j] - 1 : 0;
                if (j + 1 < grid[i].size()) {
                    each += min(grid[i][j], grid[i][j+1]);
                }
                if (i + 1 < grid.size()) {
                    each += min(grid[i][j], grid[i+1][j]);
                }
            }
        }
        return all * 6 - self * 2 - each * 2;
    }
};