class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n <= 1) {
            return;
        }
        for (int level = 0; level <= n/2 - 1; level++) {
            for (int start = level; start <= n-2-level; start++) {
                trans(matrix, n, level, start);
            }
        }
        return;
    }

    void trans(vector<vector<int>>& matrix, int n, int i, int j) {
        int element = matrix[i][j];
        int ni = j;
        int nj = n - 1 - i;
        while (ni != i || nj != j) {
            int t = matrix[ni][nj];
            matrix[ni][nj] = element;
            element = t;
            int ti = ni;
            int tj = nj;
            ni = tj;
            nj = n - 1 - ti;
        }
        matrix[i][j] = element;
        return;
    }
};