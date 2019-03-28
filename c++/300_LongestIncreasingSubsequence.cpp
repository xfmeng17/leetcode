class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	return func1(nums);
    }

    // ** dp[i] represents the LIS end at i
    int func1(vector<int>& nums) {
    	int N = nums.size();
    	if (N <= 0) return 0;
    	
    	vector<int> dp(N, 1);

  		int res = 1;
    	for (int i = 1; i < N; i++) {
    		for (int j = i-1; j >= 0; j--) {
    			if (nums[i] > nums[j]) {
    				dp[i] = max(dp[i], 1 + dp[j]);
    			}
    		}
    		res = max(res, dp[i]);
    	}

    	return res;
    }
};
