class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return func1(nums, target);
    }

    vector<int> func1(vector<int>& nums, int target) {
        vector<int> result1(2, 0);
        vector<int> result2(2, 0);
        vector<int> result(2, -1);
        binarySearch(nums, target-0.1, result1);
        binarySearch(nums, target+0.1, result2);

        if (result1[0] != result2[0] || result1[1] != result2[1]) {
            result[0] = result1[0];
            result[1] = result2[1];
        }
        
        return result;
    }

    void binarySearch(vector<int>& nums, double target, vector<int>& result) {
        int lo = 0, hi = nums.size() -1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (double(nums[mid]) > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        result[0] = lo;
        result[1] = hi;

        // printf("res0=%d, res1=%d\n", result[0], result[1]);
    }
};