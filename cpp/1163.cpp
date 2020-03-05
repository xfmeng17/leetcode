class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        return func1(grid);
    }
    int func1(vector<vector<int>>& grid) {
    	int ret = 0;
    	for (int i = 0; i < grid.size(); i++) {
    		for (int j = 0; j < grid[i].size(); j++) {
    			ret = max(ret, helper1(grid, i, j));
    		}
    	}
    	return ret;
    }
};