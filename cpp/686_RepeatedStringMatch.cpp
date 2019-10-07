class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // return func1(A, B);
        return func2(A, B);
    }
    int func1(string A, string B) {
        int res = 0;
        string s = "";
        while (s.length() < B.length()) {
            s += A;
            res++;
        }
        if (s.find(B) != string::npos) {
            return res;
        }
        s += A;
        res++;
        return s.find(B) != string::npos ? res : -1;
    }

    /**
     * Reference, more concise
     */
    int func2(string A, string B) {
        string s = A;
        for (int r = 1; r <= B.length() / A.length() + 2; r++, s += A) {
            if (s.find(B) != string::npos) {
                return r;
            }
        }
        return -1;
    }

    /**
     * Maybe I should use this problem to review KMP
     */
};
