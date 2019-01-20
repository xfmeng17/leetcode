class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	// return func1(nums);  
    	// return func2(nums);  
    	return func3(nums);
    }
    /*
    * basic dp
    * S(n, m) = Sum of nums[n] to nums[m]
    * Memory Limit Exceeded
    */
    int func1(vector<int>& nums) {
    	int n = nums.size();
    	if (n <= 0) return 0;

    	int res = nums[0];
    	vector<vector<int>> memo(n);
    	for (int i = 0; i < n; i++) {
    		memo[i].resize(n);
    		for (int j = 0; j < n; j++) {
    			if (i == j) {
    				memo[i][j] = nums[i];
    			} else {
    				memo[i][j] = memo[i][j-1] + nums[j];
    			}
    			res = max(res, memo[i][j]);
    		}
    	}

    	return res;
    }
    // ** trim space dp, O(n^2) time
    int func2(vector<int>& nums) {
    	if (nums.size() <= 0) return 0;

    	int n = nums.size();
    	int res = nums[0];
    	for (int i = 0; i < n; i++) {
    		int acc = 0;
    		for (int j = i; j < n; j++) {
    			acc += nums[j];
    			res = max(res, acc);
    		}
    	}

    	return res;
    }

    // ** O(n) time
    int func3(vector<int>& nums) {
    	int res = nums[0];
    	int pre = nums[0];
    	for (int i = 1; i < nums.size(); i++) {
    		cout << "pre = " << pre << endl;
    		if (pre < 0) {
    			pre = nums[i];
    		} else {
    			pre += nums[i];
    		}
    		res = max(res, pre);
    	}
    	return res;
    }

    // ** use hint, D&C
    int func4(vector<int>& nums) {

    }
    int helper4(vector<int>& nums, int n, int m, int link) {

    }
    int maxCrossingSum(vector<int>& nums, int lo, int mid, int hi) {
    	
    }
};
