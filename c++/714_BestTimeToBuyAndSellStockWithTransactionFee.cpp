class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // return func1(prices, fee);
        // return func2(prices, fee);
        // return func3(prices, fee);
        return func4(prices, fee);
    }

    // ** 1. recursion, top-down, time-limit-exceeded
    int func1(vector<int>& prices, int fee) {
        return helper1(prices, fee, 0, prices.size() - 1);
    }
    int helper1(vector<int>& prices, int fee, int lo, int hi) {
        if (hi <= lo) {
            return 0;
        }
        if (hi - lo == 1) {
            return max(0, prices[hi] - prices[lo] - fee);
        }

        int ret = 0;
        for (int i = lo; i < hi; i++) {
            for (int j = i+1; j <= hi; j++) {
                int p = prices[j] - prices[i] - fee;
                int lf = helper1(prices, fee, lo, i-1);
                int rt = helper1(prices, fee, j+1, hi);
                ret = max(ret, lf + p + rt);
            }
        }

        return ret;
    }

    // ** 2. recursion+memo, top-down
    int func2(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return helper2(prices, fee, 0, n-1, memo);
    }
    int helper2(vector<int>& prices, int fee, int lo, int hi, vector<vector<int>>& memo) {
        if (hi <= lo) {
            return 0;
        }
        if (hi - lo == 1) {
            memo[lo][hi] = max(0, prices[hi] - prices[lo] - fee);
            return memo[lo][hi];
        }
        if (memo[lo][hi] >= 0) {
            return memo[lo][hi];
        }

        memo[lo][hi] = 0;
        for (int i = lo; i < hi; i++) {
            for (int j = i+1; j <= hi; j++) {
                int p = prices[j] - prices[i] - fee;
                int lf = helper2(prices, fee, lo, i-1, memo);
                int rt = helper2(prices, fee, j+1, hi, memo);
                memo[lo][hi] = max(memo[lo][hi], lf + p + rt);
            }
        }

        return memo[lo][hi];
    }

    // ** 3. iteration, bottom-up
    // ** TLE O(n^3)
    int func3(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));

        // len = 2 or more
        for (int len = 2; len <= n; len++) {
            for (int lo = 0; lo <= n - len; lo++) {
                int hi = lo + len - 1;
                for (int i = lo; i < hi; i++) {
                    memo[lo][hi] = max(memo[lo][hi], memo[lo][i] + memo[i+1][hi]);
                }
                memo[lo][hi] = max(memo[lo][hi], prices[hi] - prices[lo] - fee);
            }

        }

        return memo[0][n-1];
    }

    // ** 4. not dp
    int func4(vector<int>& prices, int fee) {
        int ret = 0;
        int currLo = 0, currHi = 0;
        int lastLo = 0, lastHi = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= prices[currLo]) {
                currLo = i;
                currHi = i;
            }
            if (prices[i] >= prices[currHi]) {
                currHi = i;
            }
            if (prices[currHi] - prices[currLo] > fee) {
                if (prices[lastHi] - prices[currLo] < fee && ret > 0) {
                    ret += prices[currHi] - prices[lastHi];
                    lastHi = currHi;
                    currLo = i + 1;
                    currHi = i + 1;
                } else {
                    ret += prices[currHi] - prices[currLo] - fee;
                    lastLo = currLo;
                    lastHi = currHi;
                    currLo = i + 1;
                    currHi = i + 1;
                }
            }
        }

        if (currHi < prices.size() && lastHi > 0) {
            ret += max(0, prices[currHi] - prices[lastHi]);
        }

        return ret;
    }
};
