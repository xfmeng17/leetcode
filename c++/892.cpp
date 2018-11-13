class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
    	vector<int> x;
    	vector<int> y;
    	int z = 0;
    	int height = grid.size();
    	int width = grid[0].size();

    	for (int i = 0; i < height; i++) {
    		int max = 0;
    		for (int j = 0; j < width; j++) {
    			if (grid[i][j] > max) {
    				max = grid[i][j];
    			}
    		}
    		x.push_back(max);
    	}
    	for (int j = 0; j < width; j++) {
    		int max = 0;
    		for (int i = 0; i < height; i++) {
				if (grid[i][j] > max) {
					max = grid[i][j];
				}
    		}
    	}
    }
};