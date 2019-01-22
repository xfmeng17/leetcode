class Solution {
private:
    int MAX_VALUE = 200;
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        // return func1(A);
        return func2(A);
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
};

