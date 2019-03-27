class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	return func1(nums, k);
    }

    // ** dp[i] = sum nums from 0 to i
    // ** Time O(N^2), space O(N)
    bool func1(vector<int>& nums, int k) {
    	int N = nums.size();
    	if (N <= 1) {
    		return false;
    	}

    	vector<int> dp(N, 0);
    	dp[0] = nums[0];
    	for (int i = 1; i < N; i++) {
    		dp[i] = nums[i] + dp[i-1];
    	}

    	for (int len = N; len >= 2; len--) {
    		for (int lo = 0, hi = len - 1; hi < N; lo++, hi++) {
    			int subSum = dp[hi] - dp[lo] + nums[lo];
    			if (k == 0) {
    				if (subSum == 0) {
    					return true;
    				}
    			} else {
    				if (subSum % k == 0) {
    					return true;
    				}
    			}
    		}
    	}

    	return false;
    }
};
