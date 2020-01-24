class Solution {
public:
    int distinctEchoSubstrings(string text) {
        // return func1(text);
        return func2(text);
    }

    // TLE
    int fun1(string text) {
        int N = text.length();
        unordered_map<string, int> map;
        for (int len = 2; len <= N; len += 2) {
            for (int lo = 0; lo < N; lo++) {
                if (lo + len > N) { 
                    break; 
                }
                string sub = text.substr(lo, len);
                if (map.find(sub) != map.end()) {
                    continue;
                }
                
                bool put = true;
                for (int j = 0; j < len/2; j++) {
                    if (sub[j] != sub[j+len/2]) {
                        put = false;
                        break;
                    }
                }
                if (put) {
                    map[sub] = 1;
                } else {
                    map[sub] = 0;
                }
            }
        }
        int ret = 0;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second > 0) {
                // cout << it->first << endl;
                ret++;
            }
        }
        return ret;
    }
    
    int func2(string text) {
        int N = text.length();
        unordered_map<string, int> map;
        
        if (N <= 0) {
            return 0;
        }

        for (int len = N/2; len >= 1; len--) {
            for (int i = 0; i+2*len-1 < N; i++) {
                bool same = true;
                for (int j = 0; j < len; j++) {
                    if (text[j] != text[j+len]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    map[text.substr(i, len)]++;
                }
            }
        }

        return map.size();
    }
};