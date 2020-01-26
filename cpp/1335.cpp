class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // return func1(jobDifficulty, d);
        return func2(jobDifficulty, d);
    }
    int func1(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d) {
            return -1;
        }
        return helper1(jobDifficulty, 0, jobDifficulty.size()-1, d);
    }
    int helper1(vector<int>& jobDifficulty, int lo, int hi, int d) {
        int min_sum = 300001;
        int curr_val = -1;
        int next_sum = 0;

        if (d == 1) {
            for (int i = lo; i <= hi; i++) {
                curr_val = max(curr_val, jobDifficulty[i]);
            }
            return curr_val;
        }

        for (int mid = lo; mid <= hi - d + 1; mid++) {
            curr_val = max(curr_val, jobDifficulty[mid]);
            next_sum = helper1(jobDifficulty, mid+1, hi, d-1);
            min_sum = min(min_sum, curr_val + next_sum);
        }

        return min_sum;
    }

    int func2(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<vector<int>>> memo(d+1, vector<vector<int>>(n, vector<int>(n, 300001)));
        return helper2(jobDifficulty, 0, jobDifficulty.size()-1, d, memo);
    }
    int helper2(vector<int>& jobDifficulty, int lo, int hi, int d, vector<vector<vector<int>>>& memo) {
        int min_sum = 300001;
        int curr_val = -1;
        int next_sum = 0;

        if (memo[d][lo][hi] < 300001) {
            return memo[d][lo][hi];
        }
        if (d == 1) {
            for (int i = lo; i <= hi; i++) {
                curr_val = max(curr_val, jobDifficulty[i]);
            }
            memo[d][lo][hi] = curr_val;
            return memo[d][lo][hi];
        }

        for (int mid = lo; mid <= hi - d + 1; mid++) {
            curr_val = max(curr_val, jobDifficulty[mid]);
            next_sum = helper2(jobDifficulty, mid+1, hi, d-1, memo);
            min_sum = min(min_sum, curr_val + next_sum);
        }
        memo[d][lo][hi] = min_sum;
        return memo[d][lo][hi];
    }
};