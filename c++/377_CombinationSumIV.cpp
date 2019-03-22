class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return func1(nums, target);
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
};
