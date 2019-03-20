class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // return func1(nums);
        return func2(nums);
    }

    // ** 1D array dp
    // ** dp1[k] represents the max length that end at
    // ** nums[k] and the last difference is positive,
    // ** dp2[k] is same but last difference is negative.
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
                } else if (nums[i] < nums[j]) {
                    dp2[i] = max(dp2[i], 1 + dp1[j]);
                }
                res = max(res, max(dp1[i], dp2[i]));
            }
        }

        return res;
    }

    // ** Reference form discuss
    // ** Brilliant idea, use two array up[] and down[]
    // ** to record the max length so far at index i
    int func2(vector<int>& nums) {
        int N = nums.size();
        if (N <= 0) {
            return 0;
        }

        vector<int> up(N, 0);
        vector<int> down(N, 0);

        up[0] = 1;
        down[0] = 1;

        for (int i = 1; i < N; i++) {
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }

        return max(up[N-1], down[N-1]);
    }
};