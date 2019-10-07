class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return func1(nums, S);
        return func2(nums, S);
        // return func3(nums, S);
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
        int all = accumulate(nums.begin(), nums.end(), 0);
        if (all < S) { return 0; }
        if ((all + S) & 1) { return 0; }

        int sum = (all + S) / 2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1, 0));

        // ** When sum = 0:
        // ** dp[0][0] means we have nothing, and our goal is 0, just can pick noting => 1 choice,
        // ** dp[1][0] means we have { nums[0] }, and our goal is 0, just can noting => 1 choice,
        // ** dp[2][0] means we have { nums[0], nums[1] }, and our goal is 0, just can pick noting => 1 choice,
        // ** and so on...
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= nums.size(); i++) {
            // ** down-top, more readable in this problem

            // for (int j = 0; j <= sum; j++) {
            //     dp[i][j] = dp[i-1][j];
            //     if (j >= nums[i-1]) {
            //         dp[i][j] += dp[i-1][j - nums[i-1]];
            //     }
            // }

            // ** top-down

            int j = sum;
            for (; j >= nums[i-1]; j--) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
            }
            // ** We need to set dp[i][j] = dp[i-1][j] when current sum j
            // ** is too small to let us 'pick' a nums[i-1].
            // ** This leaves us just one condition that we get the sum j by just
            // ** repeating all ways to  get sum j through the first i-1 elements. 
            for (; j >= 0; j--) {
                dp[i][j] = dp[i-1][j];
            }
        }

        // for (int i = 0; i <= nums.size(); i++) {
        //     for (int j = 0; j <= sum; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[nums.size()][sum];
    }

    // ** dp from discuss, one-dimensional
    int func3(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S) { return 0; }
        if ((sum + S) & 1) { return 0;}

        int target = (sum + S) >> 1;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (auto n : nums) {
            for (int j = target; j >= n; j--) {
                dp[j] += dp[j-n];
            }
        }

        return dp[target];
    }
};
