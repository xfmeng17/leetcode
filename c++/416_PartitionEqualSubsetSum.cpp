class Solution {
public:
    bool canPartition(vector<int>& nums) {
        return func1(nums);     
    }
    // ** recursive
    bool func1(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto n : nums) {
            sum += n;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;

        return helper1(nums, 0, target);
    }
    bool helper1(vector<int>& nums, int i, int target) {
        if (i >= nums.size()) {
            return false;
        }
        if (target == 0) {
            return true;
        }

        int pick = helper1(nums, i+1, target - nums[i]);
        int notp = helper1(nums, i+1, target);

        return pick || notp;
    }
};
