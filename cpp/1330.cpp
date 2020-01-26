class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        return func1(nums);
    }

    int func1(vector<int>& nums) {
        int N = nums.size();
        int value = 0;
        int maxdiff = 0;
        for (int i = 0; i < N - 1; i++) {
            value += abs(nums[i] - nums[i+1]);
        }
        // printf("value=%d\n", value);
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int lo_old = nums[i];
                int lo_new = nums[j];
                int hi_old = nums[j];
                int hi_new = nums[i];
                
                int diff = 0;
                if (i > 0) {
                    diff += abs(nums[i-1] - lo_new) - abs(nums[i-1] - lo_old);
                }
                if (j < N-1) {
                    diff += abs(hi_new - nums[j+1]) - abs(hi_old - nums[j+1]);
                }
                maxdiff = max(maxdiff, diff);
            }
        }

        return value + maxdiff;
    }
};