class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        return func1(mat);
    }

    vector<vector<int>> func1(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        vector<vector<int>> ret(M, vector<int>(N, 0));

        for (int k = N-1; k >= 0; k--) {
            vector<int> temp;
            int i = 0;
            int j = k;
            while (i < M && j < N) {
                temp.emplace_back(mat[i][j]);
                i += 1;
                j += 1;
            }
            sort(temp.begin(), temp.end());
            i = 0;
            j = k;
            int idx = 0;
            while (i < M && j < N) {
                ret[i][j] = temp[idx++];
                i += 1;
                j += 1;
            }
        }
        for (int k = 1; k < M; k++) {
            vector<int> temp;
            int i = k;
            int j = 0;
            while (i < M && j < N) {
                temp.emplace_back(mat[i][j]);
                i += 1;
                j += 1;
            }
            sort(temp.begin(), temp.end());
            i = k;
            j = 0;
            int idx = 0;
            while (i < M && j < N) {
                ret[i][j] = temp[idx++];
                i += 1;
                j += 1;
            }
        }

        return ret;
    }
};