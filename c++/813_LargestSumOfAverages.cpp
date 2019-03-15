class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        return func1(A, K);
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

        double lf = 0.0;
        double rt = 0.0;
        double res = 0.0;

        for (int i = lo; i <= hi; i++) {
            lf = helper1(A, lo, i, 1);
            rt = helper1(A, i+1, hi, K-1);
            res = max(res, lf + rt);
        }

        return res;
    }
};
