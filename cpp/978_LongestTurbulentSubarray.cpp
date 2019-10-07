class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        // return func1(A);
        return func2(A);
    }

    // ** two 1D array dp
    int func1(vector<int>& A) {
        int N = A.size();
        if (N <= 1) {
            return N;
        }

        vector<int> more(N, 1);
        vector<int> less(N, 1);
        int res = 0;

        for (int i = 1; i < N; i++) {
            if (A[i-1] < A[i]) {
                more[i] = max(more[i], less[i-1] + 1);
            } else if (A[i-1] > A[i]) {
                less[i] = max(less[i], more[i-1] + 1);
            }
            res = max(res, max(more[i], less[i]));
        }

        return res;
    }

    int func2(vector<int>& A) {
        int N = A.size();
        if (N <= 1) {
            return N;
        }

        int more = 1;
        int less = 1;
        int res = 1;

        for (int i = 1; i < N; i++) {
            if (A[i-1] < A[i]) {
                more = less + 1;
                less = 1;
            } else if (A[i-1] > A[i]) {
                less = more + 1;
                more = 1;
            } else {
                more = 1;
                less = 1;
            }
            // cout<<"x="<<A[i]<<", more="<<more<<", less="<<less<<endl;
            res = max(res, max(more, less));
        }

        return res;
    }
};
