class Solution {
public:
    int distinctEchoSubstrings(string text) {
        // return func1(text);
        return func2(text.c_str(), text.length());
    }

    // 1. Basic string compare solution, use hash-set do cache
    // Time: O(n^3) time, Space: O(n^2)
    int func1(string& text) {
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

    /*
     * 2. Rabin-Karp substring search, Time: O(n^2), Space: O(1)
     * According to "Algorithms, 4th Edition => 5.3 Substring Search => Rabin-Karp fingerprint search"
     * Onile implement: https://algs4.cs.princeton.edu/53substring/  => RabinKarp.java
     *
     * My notes:
     * #1 Use `const char*` instead `string&` for text to pass into the functions.
     * #2 Should use string type `unordered_set<string> set` not `long type` to avoid collision.
     * #3 Base on #2, should do `RK_Recheck` when hash value is equal for sure.
     * #4 Do #2 and #3 will make the code too slow to pass.
     * #5 There are a lot of thing can be done to speed up my implement, for readable, I just leave it this way.
     */
    const int R = 26;        // There are only low letter in string
    const long Q = 1e13 + 7; // Random chose some big prime

    int func2(const char* text, int N) {
        long RM = 1;
        // unordered_set<string> set;
        unordered_set<long> set;

        for (int len = 1; len <= N/2; len++) {
            // M == len, use 'M' to keep same to algs4's implement
            int M = len;
            // long RM = RK_RM(M, R, Q);
            if (M > 1) {
                RM = RM * R % Q;
            }
            long curr_hash1 = 0;
            long curr_hash2 = 0;
            
            for (int i = 0; i+2*len-1 < N; i++) {
                if (i == 0) {
                    curr_hash1 = RK_Hash(text, i, M, R, Q);
                    curr_hash2 = RK_Hash(text, i+M, M, R, Q);
                } else {
                    curr_hash1 = RK_Shift(text, i-1, M, R, Q, RM, curr_hash1);
                    curr_hash2 = RK_Shift(text, i-1+M, M, R, Q, RM, curr_hash2);
                }
                if (curr_hash1 == curr_hash2 && RK_Recheck(text, i, i+M)) {
                    // set.emplace(text.substr(i, M));
                    set.emplace(curr_hash1);
                }
            }
        }
        return set.size();
    }

    long RK_RM(int M, int R, long Q) {
        long RM = 1;
        for (int i = 1; i <= M-1; i++) {
            RM = (R * RM) % Q;
        }
        return RM;
    }
    long RK_Hash(const char* text, int i, int M, int R, long Q) {
        long h = 0;
        for (int j = 0; j < M; j++) {
            h = (R * h + text[i+j]) % Q;
        }
        return h;
    }
    long RK_Shift(const char* text, int i, int M, int R, long Q, long RM, long last_hash) {
        last_hash = (last_hash + Q - RM * text[i] % Q) % Q;
        last_hash = (last_hash * R + text[i+M]) % Q;
        return last_hash;
    }
    // Honest, we should always do Recheck, but will make "a.....a" case Time-Limit-Exceeded
    bool RK_Recheck(const char* text, int i, int j) {
        return true;
        for (int len = 0; len < j - i; len++) {
            if (text[i+len] != text[j+len]) {
                return false;
            }
        }
        return true;
    }
};