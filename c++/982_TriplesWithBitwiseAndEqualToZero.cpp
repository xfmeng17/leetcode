class Solution {
public:
    int countTriplets(vector<int>& A) {
        return func1(A);
    }
    // ** iteraton, TLE
    int func1(vector<int>& A) {
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                for (int k = 0; k < A.size(); k++) {
                    if ((A[i] & A[j] & A[k]) == 0) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
