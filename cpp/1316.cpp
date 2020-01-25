class Solution {
public:
    int distinctEchoSubstrings(string text) {
        // return func1(text);
        return func2(text);
    }

    // 1. Basic string compare solution, use hash-set do cache
    // Time: O(n^3) time, Space: O(n^2)
    int func1(string text) {
        int N = text.length();
        unordered_set<string> set;

        for (int len = 1; len <= N/2; len++) {
            for (int i = 0; i+2*len-1 < N; i++) {
                string s = text.substr(i, len);
                if (set.count(s) > 0) {
                    continue;
                }
                bool same = true;
                for (int j = 0; j < len; j++) {
                    if (text[i+j] != text[i+j+len]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    set.emplace(s);
                }
            }
        }
        return set.size();
    }

    // 2. Rabin-Karp substring search
    // According to "Algorithms, 4th Edition => 5.3 Substring Search => Rabin-Karp fingerprint search"
    // Time: O(n^2), Space: O(1)
    // Onile implement: https://algs4.cs.princeton.edu/53substring/  RabinKarp.java
    
    int func2(string text) {
        const int R = 26;
        const long Q = 1e9 + 7;

        int N = text.length();
        unordered_set<string> set;
        for (int len = 1; len <= N/2; len++) {
            int M = len;
            long RM = RK_RM(M, R, Q);
            long curr_hash1 = 0;
            long curr_hash2 = 0;
            // M == len, use 'M' to keep same to algs4's implement
            for (int i = 0; i+2*len-1 < N; i++) {
                if (i == 0) {
                    curr_hash1 = RK_Hash(text, i, M, R, Q);
                    curr_hash2 = RK_Hash(text, i+M, M, R, Q);
                } else {
                    curr_hash1 = RK_Shift(text, i, M, R, Q, RM, curr_hash1);
                    curr_hash2 = RK_Shift(text, i+M, M, R, Q, RM, curr_hash2);
                }
                printf("i=%d, curr_hash1=%ld, curr_hash2=%ld\n", i, curr_hash1, curr_hash2);
                if (curr_hash1 == curr_hash2 && RK_Recheck(text, i, i+M)) {
                    set.emplace(text.substr(i, i+M));
                }
            }
        }
        return set.size();
    }

    long RK_RM(int M, int R, long Q) {
        long RM = R;
        int time = M-2;
        while (time-- > 0) {
            RM *= R;
            RM %= Q;
        }
        return RM;
    }
    long RK_Hash(string text, int i, int M, int R, long Q) {
        long hash = 0;
        while (i++ < M) {
            hash += (hash * R) + (text[i] - '0');
            hash %= Q;
        }
        return hash;
    }
    long RK_Shift(string text, int i, int M, int R, long Q, long RM, long last_hash) {
        int last_val = text[i-1] - '0';
        int curr_val = text[i+M-1] - '0';
        long curr_hash = (last_hash + last_val*(Q - RM)) * R + curr_val;
        curr_hash %= Q;
        return curr_hash;
    }
    bool RK_Recheck(string text, int i, int j) {
        for (int len = 0; len < j - i; len++) {
            if (text[i+len] != text[j+len]) {
                return false;
            }
        }
        return true;
    }
};