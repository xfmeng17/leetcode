class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // return func1(nums);
        return func2(nums);
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
        return helper1(singleNums, singleSize, 0, singleNums.size()-1);
    }
    int helper1(vector<int>& singleNums, vector<int>& singleSize, int lo, int hi) {
        if (lo < 0 || hi >= singleNums.size() || lo > hi) {
            return 0;
        }
        int ret = 0;
        for (int i = lo; i <= hi; i++) {
            int lf = 0;
            if (i-1 >= 0) {
                if (singleNums[i-1] == singleNums[i]-1) {
                    lf = helper1(singleNums, singleSize, lo, i-2);
                } else {
                    lf = helper1(singleNums, singleSize, lo, i-1);
                }
            }
            int rt = 0;
            if (i+1 <= hi) {
                if (singleNums[i+1] == singleNums[i]+1) {
                    rt = helper1(singleNums, singleSize, i+2, hi);
                } else {
                    rt = helper1(singleNums, singleSize, i+1, hi);
                }
            }
            int cur = lf + rt + singleNums[i] * singleSize[i];
            ret = max(ret, cur);
        }

        return ret;
    }
    
    // ** recursive + memoization, still TLE
    int func2(vector<int>& nums) {
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
        
        int n = singleNums.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        
        return helper2(singleNums, singleSize, 0, n-1, memo);
    }
    int helper2(vector<int>& singleNums, vector<int>& singleSize,
        int lo, int hi, vector<vector<int>>& memo) {

        if (lo < 0 || hi >= singleNums.size() || lo > hi) {
            return 0;
        }
        if (memo[lo][hi] > 0) {
            return memo[lo][hi];
        }

        for (int i = lo; i <= hi; i++) {
            int lf = 0;
            if (i-1 >= 0) {
                if (singleNums[i-1] == singleNums[i]-1) {
                    lf = helper2(singleNums, singleSize, lo, i-2, memo);
                } else {
                    lf = helper2(singleNums, singleSize, lo, i-1, memo);
                }
            }
            int rt = 0;
            if (i+1 <= hi) {
                if (singleNums[i+1] == singleNums[i]+1) {
                    rt = helper2(singleNums, singleSize, i+2, hi, memo);
                } else {
                    rt = helper2(singleNums, singleSize, i+1, hi, memo);
                }
            }
            memo[lo][hi] = max(memo[lo][hi], lf + rt + singleNums[i] * singleSize[i]);
        }

        return memo[lo][hi];
    }
};
