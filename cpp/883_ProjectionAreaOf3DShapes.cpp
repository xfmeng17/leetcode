class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy = 0;
        for (vector<int> line : grid) {
        	for (int point : line) {
        		if (point > 0) {
        			xy++;
        		}
        	}
        }
        int xz = 0;
        for (vector<int> line : grid) {
        	int max = 0;
        	for (int point : line) {
        		if (point > max) {
        			max = point;
        		}
        	}
        	xz += max;
        }
        int yz = 0;
        int size = grid.size();
        for (int j = 0; j < size; j++) {
        	int max = 0;
        	for (int i = 0; i < size; i++) {
        		if (grid[i][j] > max) {
        			max = grid[i][j];
        		}
        	}
        	yz += max;
        }

        return xy + xz + yz;
    }
};