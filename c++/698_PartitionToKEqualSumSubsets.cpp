class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // return func1(nums, k);
        return func2(nums, k);
    }

    // ** WA, case [10,10,10,7,7,7,6,6,6]
    bool func1(vector<int>& nums, int k) {
        int all = 0;
        for (auto n : nums) {
            all += n;
        }
        if (all % k != 0) {
            return false;
        }
        int sum = all / k;

        vector<int> memo(k, 0);
        for (auto n : nums) {
            for (int i = 0; i < k; i++) {
                if (memo[i] + n <= sum) {
                    memo[i] += n;
                    break;
                }
            }
        }

        bool res = true;
        for (auto m : memo) {
            if (m != sum) {
                res = false;
            }
        }

        return res;
    }

    // ** backtracking
    // ** time O(k^N), N = nums.size(), TLE
    bool func2(vector<int>& nums, int k) {
        int all = 0;
        for (auto n : nums) {
            all += n;
        }
        if (all % k != 0) {
            return false;
        }
        int sum = all / k;
        vector<int> memo(k, 0);

        return helper2(nums, 0, memo, sum);
    }
    bool helper2(vector<int>& nums, int idx, vector<int>& memo, int sum) {
        if (idx >= nums.size()) {
            for (auto m : memo) {
                if (m != sum) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < memo.size(); i++) {
            memo[i] += nums[idx];
            if (helper2(nums, idx+1, memo, sum)) {
                return true;
            } else {
                memo[i] -= nums[idx];
            }
        }

        return false;
    }
};
