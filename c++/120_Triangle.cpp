class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return func1(triangle);
    }

    // ** recursive
    int func1(vector<vector<int>>& triangle) {
        return helper1(triangle, 0, 0);
    }
    int helper1(vector<vector<int>>& triangle, int l, int c) {
        if (l == triangle.size() - 1) {
            return triangle[l][c];
        }

        int curr = triangle[l][c];
        int lf = helper1(triangle, l+1, c);
        int rt = helper1(triangle, l+1, c+1);

        return curr + min(lf, rt);
    }

    // ** recursive + memoization
    int func2(vector<vector<int>>& triangle) {
        int N = triangle.size();
        vector<vector<int>> memo(N, vector<int>(N+1, 0));
        return helper2(triangle, 0, 0, memo);
    }
    int helper2(vector<vector<int>>& triangle, int l, int c,
        vector<vector<int>>& memo) {
        
        if (l == triangle.size() - 1) {
            return triangle[l][c];
        }
        if (memo[l][c] != 0) {
            return memo[l][c];
        }

        int curr = triangle[l][c];
        int lf = helper2(triangle, l+1, c, memo);
        int rt = helper2(triangle, l+1, c+1, memo);
        memo[l][c] = curr + min(lf, rt);

        return memo[l][c];
    }
};
