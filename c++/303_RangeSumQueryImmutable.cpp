// ** O(n^2) time and space
/*
class NumArray {
public:
    NumArray(vector<int> nums) {
    	int size = nums.size();
    	range.resize(size);
    	for (int i = 0; i < size; i++) {
    		range[i].resize(size);
    	}
    	for (int i = 0; i < size; i++) {
    		for (int j = 0; j < size; j++) {
    			if (i < j) {
    				range[i][j] = range[i][j-1] + nums[j];
    			} else {
    				range[i][j] = nums[j];
    			}
    		}
    	}
    }
    
    int sumRange(int i, int j) {
    	return range[i][j];
    }
private:
	vector<vector<int>> range;
};
*/

// ** referance, O(n) time and space
class NumArray {
public:
    NumArray(vector<int> nums) {
    	acc.push_back(0);
    	for (int num : nums) {
    		acc.push_back(acc.back() + num);
    	}
    }
    int sumRange(int i, int j) {
    	return acc[j+1] - acc[i];
    }
private:
	vector<int> acc;
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
