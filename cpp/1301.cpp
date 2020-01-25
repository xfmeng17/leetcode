class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        return func1(board);
    }

    vector<int> func1(vector<string>& board) {
        int M = board.size();
        int N = board[0].size();

        vector<int> ans(2, 0);
        vector<vector<int>> memo(M, vector<int>(N, -1));
        vector<vector<int>> nums(M, vector<int>(N, 0));
        nums[0][0] = 1;
        int ret = helper1(board, M-1, N-1, memo, nums);
        
        if (memo[0][0] == -1) {
            return ans;
        }
        ans[0] = ret;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                // printf("memo[%d][%d]=%d, nums=%d\n", i, j, memo[i][j], nums[i][j]);
                if (memo[i][j] == ans[0] ) {
                    ans[1] += nums[i][j];
                }
            }
        }
        ans[0] -= 1;

        return ans; 
    }

    int helper1(vector<string>& board, int i, int j,
                vector<vector<int>>& memo, vector<vector<int>>& nums) {
        if (i == 0 && j == 0) {
            memo[0][0] = 0;
            return 0;
        }
        if (memo[i][j] >= 0) {
            return memo[i][j];
        }
  
        int up = -1;
        int up_left = -1;
        int left = -1;
        int curr = board[i][j] == 'S' ? 1 : board[i][j] - '0';
        if (i-1 >= 0 && board[i-1][j] != 'X') {
            up = curr + helper1(board, i-1, j, memo, nums);
        }
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != 'X') {
            up_left = curr + helper1(board, i-1, j-1, memo, nums);
        }
        if (j-1 >= 0 && board[i][j-1] != 'X') {
            left = curr + helper1(board, i, j-1, memo, nums);
        }

        if (up > -1) {
            if (up == memo[i][j]) {
                nums[i][j] += nums[i-1][j];
            } else if (up > memo[i][j]) {
                memo[i][j] = up;
                nums[i][j] = nums[i-1][j];
            }
        }
        if (up_left > -1) {
            if (up_left == memo[i][j]) {
                nums[i][j] += nums[i-1][j-1];
            } else if (up_left > memo[i][j]) {
                memo[i][j] = up_left;
                nums[i][j] = nums[i-1][j-1];
            }
        }
        if (left > -1) {
            if (left == memo[i][j]) {
                nums[i][j] += nums[i][j-1];
            } else if (left > memo[i][j]) {
                memo[i][j] = left;
                nums[i][j] = nums[i][j-1];
            }
        }

        memo[i][j] = memo[i][j] % MOD;
        nums[i][j] = nums[i][j] % MOD;

        return memo[i][j];
    }
};