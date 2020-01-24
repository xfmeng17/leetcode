class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        return func1(board);
    }

    vector<int> func1(vector<string>& board) {
        int M = board.size();
        int N = board[0].size();

        vector<vector<int>> memo(M, vector<int>(N, 0));
        vector<int> ret(2, 0);

        helper1(board, M-1, N-1, memo, ret);
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("memo[%d][%d]=%d\n", i, j, memo[i][j]);
            }
        }
        if (memo[0][0] != -1) {
            ret[0] = 0;
            ret[1] = 0;
        }

        return ret; 
    }

    int helper1(vector<string>& board, int i, int j, vector<vector<int>>& memo, vector<int>& ret) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i == 0 && j == 0) {
            return 0;
        }
        if (memo[i][j] > 0) {
            return memo[i][j];
        }
        
        int up = 0;
        int up_left = 0;
        int left = 0;

        int curr = board[i][j] == 'S' ? 0 : board[i][j] - '0';
        if (i-1 >= 0 && board[i-1][j] != 'X') {
            up = curr + helper1(board, i-1, j, memo, ret);
            if (up > ret[0]) {
                ret[0] = up;
                ret[1] = 1;
            } else if (up == ret[0]) {
                ret[1]++;
            }
        }
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != 'X') {
            up_left = curr + helper1(board, i-1, j-1, memo, ret);
            if (up_left > ret[0]) {
                ret[0] = up_left;
                ret[1] = 1;
            } else if (up_left == ret[0]) {
                ret[1]++;
            }
        }
        if (j-1 >= 0 && board[i][j-1] != 'X') {
            left = curr + helper1(board, i, j-1, memo, ret);
            if (left > ret[0]) {
                ret[0] = left;
                ret[1] = 1;
            } else if (left == ret[0]) {
                ret[1]++;
            }
        }
        memo[i][j] = max(up, max(up_left, left));

        return memo[i][j];
    }
};