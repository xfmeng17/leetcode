class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int column = nums[0].size();
        if ((row * column) != (r * c)) {
        	return nums;
        }

        vector<vector<int>> ans (r);
        int k = 0;
        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < column; j++) {
        		if (ans[k].size() < c) {
        			ans[k].push_back(nums[i][j]);
        		} else {
        			ans[++k].push_back(nums[i][j]);
        		}
        	}
        }

        return ans;
    }
};
