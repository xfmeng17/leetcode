class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    	return func1(nums);
    }

    /* two 1D array dp
     * dp[i] represents the length of LIS that end at nums[i]
     * dp[i] = max{1 + dp[x]} where x=[0, i-1] and nums[i] > nums[x]
     * cnt[i] stores the number of LIS that end at nums[i]
    */
    int func1(vector<int>& nums) {
    	int N = nums.size();
    	if (N <= 0) {
    		return 0;
    	}

    	vector<int> dp(N, 1);
    	vector<int> cnt(N, 1);
    	int maxLen = 1;
    	for (int i = 0; i < N; i++) {
    		for (int j = i-1; j >= 0; j--) {
    			if (nums[i] > nums[j]) {
    				if (dp[i] < 1 + dp[j]) {
    					dp[i] = 1 + dp[j];
    					cnt[i] = cnt[j];
    				} else if (dp[i] == 1 + dp[j]) {
    					cnt[i] += cnt[j];
    				}
    				maxLen = max(maxLen, dp[i]);
    			}
    		}
    	}
    	// for (int i = 0; i < N; i++) {
    	// 	cout << nums[i] << " dp= " << dp[i] << ", cnt=" << cnt[i] << endl;
    	// }

    	int res = 0;
    	for (int i = 0; i < N; i++) {
    		if (dp[i] == maxLen) {
    			res += cnt[i];
    		}
    	}

    	return res;
    }
};
