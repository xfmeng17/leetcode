class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
    	int res = 0;
        for (int i = 0; i < grid.size(); i++) {
        	for (int j = 0; j < grid[i].size(); j++) {
        		int s = gird[i][j] > 0 ? 2 : 0;
        		if (i - 1 < 0 || grid[i-1][j] < grid[i][j]) s += grid[i][j];
        		if (i + 1 >= grid.size() || grid[i+1][j] < grid[i][j]) s += grid[i][j];
        		if (j - 1 < 0 || grid[i][j-1] < grid[i][j]) s += grid[i][j];
        		if (j + 1 >= grid[i].size() || grid[i][j+1] < grid[i][j]) s += grid[i][j];
        		res += s;
        	}
        }
        return res;
    }
};