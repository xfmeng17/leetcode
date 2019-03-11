class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        return func1(nums);
    }

    // ** top-down recursive, TLE
    int func1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> singleNums;
        vector<int> singleSize;
        for (auto n : nums) {
            if (singleNums.size() > 0 && singleNums.back() == n) {
                singleSize.back()++;
            } else {
                singleNums.push_back(n);
                singleSize.push_back(1);
            }
        }
        return helper1(singleNums, 0, singleNums.size()-1, singleSize);
    }
    int helper1(vector<int>& singleNums, int lo, int hi, vector<int>& singleSize) {
        if (lo < 0 || hi >= singleNums.size() || lo > hi) {
            return 0;
        }
        int ret = 0;
        for (int i = lo; i <= hi; i++) {
            int lf = 0;
            if (i-1 >= 0) {
                if (singleNums[i-1] == singleNums[i]-1) {
                    lf = helper1(singleNums, lo, i-2, singleSize);
                } else {
                    lf = helper1(singleNums, lo, i-1, singleSize);
                }
            }
            int rt = 0;
            if (i+1 <= hi) {
                if (singleNums[i+1] == singleNums[i]+1) {
                    rt = helper1(singleNums, i+2, hi, singleSize);
                } else {
                    rt = helper1(singleNums, i+1, hi, singleSize);
                }
            }
            int cur = lf + rt + singleNums[i] * singleSize[i];
            ret = max(ret, cur);
        }

        return ret;
    }
};
