class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	int ans = 0;
    	for (int i = 0; i < grid.size(); i++) {
    		for (int j = 0; j < grid[i].size(); j++) {
    			int res = find(i, j, grid);
    			if (res > ans) {
    				ans = res;
    			}
    		}
    	}
    	return ans;
    }

    // helper functions 
    int find(int i, int j, vector<vector<int>>& grid) {
    	if (grid[i][j] == 0) {
    		return 0;
    	}
    	int sum = 1;
    	grid[i][j] = 0;
    	// up
    	if (i - 1 >= 0) {
    		sum += find(i - 1, j, grid);
    	}
    	// down
    	if (i + 1 < grid.size()) {
    		sum += find(i + 1, j, grid);
    	}
    	// left
    	if (j - 1 >= 0) {
    		sum += find(i, j - 1, grid);
    	}
    	// right
    	if (j + 1 < grid[i].size()) {
    		sum += find(i, j + 1, grid);
    	}
    	return sum;
    }
};
