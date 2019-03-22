class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // return func1(nums, target);
        return func2(nums, target);
    }

    // ** iterative
    int func1(vector<int>& nums, int target) {
        return helper1(nums, 0, target);
    }
    int helper1(vector<int>& nums, int sum, int target) {
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += helper1(nums, sum + nums[i], target);
        }
        return res;
    }

    // ** 1D array dp
    int func2(vector<int>& nums, int target) {
        // vector<int> dp(target+1, 0);
        vector<unsigned int> dp(target+1, 0);
        for (auto n : nums) {
            if (n <= target) {
                dp[n] = 1;
            }
        }
        for (int i = 1; i <= target; i++) {
            for (auto n : nums) {
                if (i - n > 0) {
                    dp[i] += dp[i-n];
                }
            }
        }
        for (int i = 0; i <= target; i++) {
            if (dp[i] > 1000000) {
                cout<<"i="<<i<<", v="<<dp[i]<<endl;
            }
            
        }
        return dp[target];

        // vector<int> dp(target+1, 0);
        // dp[0] = 1;
        // for (int i = 1; i <= target; i++) {
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (i >= nums[j]) {
        //             dp[i] += dp[i-nums[j]];
        //         }
        //     }
        // }
        // return dp[target];
    }
};
