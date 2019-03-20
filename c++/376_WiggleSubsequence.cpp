class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        return func1(nums);
    }

    // ** 1D array dp
    // ** dp1[k] represents the max wiggle subsequence
    // ** length that end at nums[k] and the last difference
    // ** is positive, dp2[k] is same but last difference
    // ** is negative.
    int func1(vector<int>& nums) {
        int N = nums.size();
        if (N <= 0) {
            return 0;
        }
        vector<int> dp1(N, 0);
        vector<int> dp2(N, 0);
        int res = 1;

        dp1[0] = 1;
        dp2[0] = 1;
        
        for (int i = 1; i < N; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp1[i] = max(dp1[i], 1 + dp2[j]);
                } else  if (nums[i] < nums[j]) {
                    dp2[i] = max(dp2[i], 1 + dp1[j]);
                }
                res = max(res, max(dp1[i], dp2[i]));
            }
        }

        return res;
    }
};