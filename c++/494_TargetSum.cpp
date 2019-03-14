class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return func1(nums, S);
        return func2(nums, S);  
    }
    
    int func1(vector<int>& nums, int S) {
        return helper1(nums, 0, S, 0);       
    }
    int helper1(vector<int>& nums, int i, int S, int sum) {
        if (i >= nums.size()) {
            return 0;
        }

        int plus = 0;
        int minus = 0;
        if (i == nums.size() - 1) {
            if (sum + nums[i] == S) plus = 1;
            if (sum - nums[i] == S) minus = 1;
        } else {
            plus = helper1(nums, i+1, S, sum + nums[i]);
            minus = helper1(nums, i+1, S, sum - nums[i]);
        }

        return plus + minus;
    }

    // ** dp from discuss, two-dimensional
    // ** Memory Limit Exceeded
    int func2(vector<int>& nums, int S) {
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        sum += S;

        if (sum & 1) {
            return 0;
        }

        int plus = sum / 2;

        vector<vector<int>> dp(nums.size()+1, vector<int>(plus+1, 0));
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = plus; j - nums[i-1] >= 0; j--) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
            }
        }

        // for (int i = 0; i <= nums.size(); i++) {
        //     for (int j = 0; j <= plus; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[nums.size()][plus];
    }
};
