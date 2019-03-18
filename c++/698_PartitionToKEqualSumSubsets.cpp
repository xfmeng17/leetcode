class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        // return func1(nums, k);
        // return func2(nums, k);
        // return func3(nums, k);
        return func4(nums, k);
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
        vector<int> subset(k, 0);

        return helper2(nums, 0, subset, sum);
    }
    bool helper2(vector<int>& nums, int idxN, vector<int>& subset, int sum) {
        if (idxN >= nums.size()) {
            for (auto m : subset) {
                if (m != sum) {
                    return false;
                }
            }
            return true;
        }

        for (int i = 0; i < subset.size(); i++) {
            subset[i] += nums[idxN];
            if (helper2(nums, idxN+1, subset, sum)) {
                return true;
            } else {
                subset[i] -= nums[idxN];
            }
        }

        return false;
    }

    // ** backtracking with memoization
    bool func3(vector<int>& nums, int k) {
        int all = 0;
        for (auto n : nums) {
            all += n;
        }
        if (all % k != 0) {
            return false;
        }
        int sum = all / k;
        vector<int> subset(k, 0);
        vector<vector<int>> memo(nums.size()+1, vector<int>(k, 0));
        
        return helper3(nums, 0, subset, sum, memo);
    }

    bool helper3(vector<int>& nums, int idxN, vector<int>& subset, int sum,
        vector<vector<int>>& memo) {

        if (idxN == nums.size()) {
            for (auto s : subset) {
                if (s != sum) { return false; }
            }
            return true;
        }

        for (int i = 0; i < subset.size(); i++) {
            subset[i] += nums[idxN];
            if (helper3(nums, idxN+1, subset, sum, memo)) {
                memo[idxN][i] = 1;
                return true;
            } else {
                memo[idxN][i] = -1;
                subset[i] -= nums[idxN];
            }
        }

        return false;
    }

    // ** pq with sort ?
    // ** WA case: nums = [2,2,10,5,2,7,2,2,13], k = 3
    bool func4(vector<int>& nums, int k) {
        int all = 0;
        for (auto n : nums) {
            all += n;
        }
        if (all % k != 0) {
            return false;
        }
        int sum = all / k;

        priority_queue<int, vector<int>, greater<int>> pq;
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i >= 0; i--) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else {
                int t = pq.top();
                pq.pop();
                pq.push(t + nums[i]);
            }
        }

        while (!pq.empty()) {
            int t = pq.top();
            pq.pop();
            if (t != sum) {
                return false;
            }
        }

        return true;
    }
};
