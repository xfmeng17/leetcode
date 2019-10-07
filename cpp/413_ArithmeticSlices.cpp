class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        return func1(A);    
    }
    // ** iterative + variables bottom-up, really fast
    int func1(vector<int>& A) {
        int res = 0;
        int n = A.size();
        int lo = 0, hi = 2;
        while (hi < n) {
            if (A[hi] - A[hi-1] == A[hi-1] - A[hi-2]) {
                hi++;
            } else {
                if (hi - lo >= 3) {
                    // ** arithmetic slice is A[lo, hi - 1]
                    int len = hi - lo;
                    res += (len - 1) * (len - 2) / 2;
                }
                lo = hi - 1;
                hi = lo + 2;
            }
        }
        if (hi - lo >= 3) {
            // ** arithmetic slice is A[lo, hi - 1]
            int len = hi - lo;
            res += (len - 1) * (len - 2) / 2;
        }

        return res;
    }
};
