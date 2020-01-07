class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return func1(matrix);
    }

    int func1(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int max = 0;
        helper1(matrix, 0, 0, n, &max);
        return max * max;
    }
    bool helper1(vector<vector<char>>& matrix, int i, int j, int len, int* maxp) {
        if (len <= 0) {
            return false; 
        }
        if (len == 1 && matrix[i][j] == '1') {
            *maxp = max(*maxp, 1);
            return true;
        }

        bool a = helper1(matrix, i, j, len-1, maxp);
        bool b = helper1(matrix, i, j+1, len-1, maxp);
        bool c = helper1(matrix, i+1, j, len-1, maxp);
        bool d = helper1(matrix, i+1, j+1, len-1, maxp);

        if (a && b && c && d) {
            *maxp = max(*maxp, len);
        }

        return false;
    }

    int func2(vector<vector<char>>& matrix) {
        return 0;
    }
    int func3(vector<vector<char>>& matrix) {
        return 0;
    }
    int func4(vector<vector<char>>& matrix) {
        return 0;
    }
};