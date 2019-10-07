class Solution {
public:
    int countTriplets(vector<int>& A) {
        // return func1(A);
        // return func2(A);
        // return func3(A);
        return func4(A);
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

    int func2(vector<int>& A) {
        int res = 0;
        int N = A.size();

        for (int i = 0; i < N; i++) {
            if (A[i] == 0) {
                res += 1;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && (A[i] & A[j]) == 0) {
                    res += 3;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    if ((A[i] & A[j] & A[k]) == 0) {
                        res += 6;
                    }
                }
            }
        }

        return res;
    }

    // ** store pair count into map
    int func3(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> map;
        for (auto x : A) {
            for (auto y : A) {
                map[x&y]++;
            }
        }
        for (auto x : A) {
            for (auto m : map) {
                if ((x & m.first) == 0) {
                    res += m.second;
                }
            }
        }
        return res;
    }

    // ** store pair result into 1 << 16 size array
    int func4(vector<int>& A) {
        int res = 0;
        int N = A.size();
        vector<int> pairResult((1 << 16), 0);

        for (auto x : A) {
            for (auto y : A) {
                pairResult[x&y]++;
            }
        }

        for (auto x : A) {
            for (int i = 0; i < (1 << 16); i++) {
                if ((x & i) == 0) {
                    res += pairResult[i];
                }
            }
        }

        return res;
    }
};
