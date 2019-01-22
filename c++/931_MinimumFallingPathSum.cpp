class Solution {
private:
    int MAX_VALUE = 200;
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        return func1(A);
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
};

