class Solution {
private:
    int MAX_VALUE = 200;
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // return func1(A);
        // return func2(A);
        return func3(A);
    }
    // ** recursive top-down
    // ** Time Limit Exceeded
    int func1(vector<vector<int>>& A) {
        if (A.size() <= 0) { return 0; }
        int res = MAX_VALUE;
        for (int i = 0; i < A[0].size(); i++) {
            res = min(res, helper1(A, 0, i));
        }

        return res;
    }
    int helper1(vector<vector<int>>& A, int row, int col) {
        if (row >= A.size()) {
            return 0;
        }
        if (col < 0 || col >= A[row].size()) {
            return MAX_VALUE;
        }
    	int sum = A[row][col];
    	int left = helper1(A, row + 1, col - 1);
        int mid = helper1(A, row + 1, col);
        int right = helper1(A, row + 1, col + 1);

        return sum + min(left, (min(mid, right)));
    }

    // ** recursive + memo (top-down)
    int func2(vector<vector<int>>& A) {
        if (A.size() <= 0) {
            return 0;
        }

        int n = A.size();
        int res = MAX_VALUE;
        vector<vector<int>> memo;
        for (int i = 0; i < n; i++) {
            vector<int> vec(A[i].size(), MAX_VALUE);
            memo.push_back(vec);
        }

        for (int i = 0; i < n; i++) {
            res = min(res, helper2(A, 0, i, memo));
        }

        return res;
    }
    int helper2(vector<vector<int>>& A, int row, int col, vector<vector<int>>& memo) {
        if (row >= A.size()) {
            return 0;
        }
        if (col < 0 || col >= A[row].size()) {
            return MAX_VALUE;
        }
        if (memo[row][col] < MAX_VALUE) {
            return memo[row][col];
        }
        cout<<"row="<<row<<"col="<<col<<endl;
        int left = helper2(A, row+1, col-1, memo);
        int mid = helper2(A, row+1, col, memo);
        int right = helper2(A, row+1, col+1, memo);
        int res = A[row][col] + min(left, min(mid, right));
        memo[row][col] = res;

        return res;
    }

    // ** iterative + memo (bottom-up)
    int func3(vector<vector<int>>& A) {
        if (A.size() <= 0) {
            return 0;
        }

        int n = A.size();
        vector<vector<int>> memo(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < A[i].size(); j++) {
                int pre = MAX_VALUE;
                // ** left-top
                if (i - 1 >= 0 && j - 1 >= 0) {
                    pre = min(pre, memo[i-1][j-1]);
                }
                // ** top
                if (i - 1 >= 0 && j >= 0) {
                    pre = min(pre, memo[i-1][j]);
                }
                // ** right-top
                if (i - 1 >= 0 && j + 1 < A[i].size()) {
                    pre = min(pre, memo[i-1][j+1]);
                }
                int cur = A[i][j];
                if (pre < MAX_VALUE) {
                    cur += pre;
                }
                memo[i].push_back(cur);
            }
        }

        vector<int>& lastRow = memo[A.size() - 1];
        if (lastRow.size() <= 0) {
            return 0;
        }
        int res = lastRow[0];
        for (int i = 0; i < n; i++) {
            res = min(res,lastRow[i]);
        }

        return res;
    }
    // ** iterative + N variables (bottom-up)
    int func4(vector<vector<int>>& A) {
        if (A.size() <= 0 || A[0].size() <= 0) {
            return 0;
        }

        int n = A.size();
        vector<int> memo(A[0].begin(), A[0].end());
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cur = memo[j];
                if (j - 1 >= 0) {
                    cur = min(cur, memo[j-1]);
                }
                if (j + 1 < n) {
                    cur = min(cur, memo[j+1]);
                }
                memo[j] = cur + A[i][j];
            }
        }
        int res = memo[0];
        for (int j = 0; j < n; j++) {
            res = min(res, memo[j]);
        }
        return res;
    }
};

