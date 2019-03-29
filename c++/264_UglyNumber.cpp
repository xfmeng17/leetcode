class Solution {
public:
    int nthUglyNumber(int n) {
        // return func1(n);
        return func2(n);
    }

    // ** hash set
    // ** TLE
    int func1(int n) {
        unordered_set<int> table;
        table.insert(1);
        int len = 1;
        int curr = 1;
        int last = 1;

        while (table.size() < n) {
            curr++;
            if (curr % 2 == 0 && table.count(curr/2) > 0) {
                table.insert(curr);
                last = curr;
            } else if (curr % 3 == 0 && table.count(curr/3) > 0) {
                table.insert(curr);
                last = curr;
            } else if (curr % 5 == 0 && table.count(curr/5) > 0) {
                table.insert(curr);
                last = curr;
            }
        }

        return last;
    }

    // ** Reference
    int func2(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> dp(n, 0);
        dp[0] =1;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[i2]*2, min(dp[i3]*3, dp[i5]*5));
            if (dp[i] == dp[i2] * 2) i2++;
            if (dp[i] == dp[i3] * 3) i3++;
            if (dp[i] == dp[i5] * 5) i5++;
        }

        return dp[n-1];
    }

};
