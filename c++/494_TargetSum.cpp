class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return func1(nums, S);      
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
};
