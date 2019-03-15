class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        // return func1(A, K);
        return func2(A, K);
    }

    double func1(vector<int>& A, int K) {
        return helper1(A, 0, A.size()-1, K);
    }

    double helper1(vector<int>& A, int lo, int hi, int K) {
        if (lo > hi) {
            return 0.0;
        }
        if (K == 1) {
            double sum = 0.0;
            for (int i = lo; i <= hi; i++) {
                sum += A[i];
            }
            return sum / (hi - lo + 1.0);
        }
        if (K == (hi - lo + 1)) {
            double sum = 0.0;
            for (int i = lo; i <= hi; i++) {
                sum += A[i];
            }
            return sum;
        }

        double res = 0.0;
        for (int i = lo; i <= hi; i++) {
            double lf = helper1(A, lo, i, 1);
            double rt = helper1(A, i+1, hi, K-1);
            res = max(res, lf + rt);
        }

        return res;
    }

    // ** recursive + memoization
    // ** O(K*N^2) time complexity, TLE
    double func2(vector<int>& A, int K) {
        int N = A.size();
        if (N <= 0 || K <= 0) {
            return 0.0;
        }
        
        vector<vector<double>> memo(N, vector<double>(N, 0.0));
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (j == i) {
                    memo[i][j] = A[j];
                } else {
                    memo[i][j] = A[j] + memo[i][j-1];
                }
                // cout<<memo[i][j]<<" ";
            }
            // cout<<endl;
        }

        return helper2(A, 0, N-1, K, memo);
    }
    double helper2(vector<int>& A, int lo, int hi, int K,
        vector<vector<double>>& memo) {

        if (lo > hi) {
            return 0.0;
        }
        if (K == 1) {
            return memo[lo][hi] / (hi - lo + 1.0);
        }
        if (K == hi - lo + 1) {
            return memo[lo][hi];
        }

        double res = 0.0;
        for (int mid = lo; mid <= hi; mid++) {
            double lf = helper2(A, lo, mid, 1, memo);
            double rt = helper2(A, mid+1, hi, K-1, memo);
            res = max(res, lf + rt);
        }

        return res;
    }
};
