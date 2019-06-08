class Solution {
public:
    bool isValid(string S) {
      return func1(S);  
    }

    bool func1(string S) {
        int N = S.length();
        int i = 0;
        int j = N - 1;
        while (j > i) {
            if (S[i] == 'a') {
                if (i+1 <= j && S[i+1] == 'b') {
                    if (i+2 <= j && S[i+2] == 'c') {
                        i += 3;
                    } else {
                        if (S[j] == 'c') {
                            i += 2;
                            j -= 1;
                        } else {
                            return false;
                        }
                    }
                } else {
                    if (j-1 >= 0 && S[j-1] == 'b' && S[j] == 'c') {
                        i += 1;
                        j -= 2;
                    } else {
                        return false;
                    }
                }
            } else if (S[i] == 'b') {
                if (i+1 < N && S[i+1] == 'c' && S[j] == 'a') {
                    i += 2;
                    j -= 1;
                } else {
                    return false;
                }
            } else if (S[i] == 'c') {
                if (j-1 >= 0 && S[j-1] == 'a' && S[j] == 'b') {
                    i += 1;
                    j -= 2;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
