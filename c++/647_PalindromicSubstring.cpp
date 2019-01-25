class Solution {
public:
    int countSubstrings(string s) {
        // return func1(s); 
        // return func2(s);
        // return func3(s);
        // return func4(s);
        // return func5(s);
        // return func6(s);
        return func7(s);
    }

    // ** recursive (top-down)
    // ** slow
    int func1(string s) {
        int res = 0;
        for (int len = s.length(); len >= 1; len--) {
            res += helper1(s.substr(0, len));
        }
        return res;
    }
    int helper1(string s) {
        int len = s.length();
        if (len <= 0) { return 0; }
        if (len == 1) { return 1; }
        
        int curr = isPalindromic(s);
        int tail = helper1(s.substr(1));
        
        return curr + tail;
    }
    // ** get all substrings first
    // ** super slow
    int func2(string s) {
        vector<string> subStrVec;
        allSubString(s, subStrVec);
        int res = 0;
        for (int i = 0; i < subStrVec.size(); i++) {
            res += isPalindromic(subStrVec[i]);
        }
        return res;
    }
    // ** recursive (top-down) more concise
    // ** slow
    int func3(string s) {
        int len = s.length();
        if (len == 0) { return 0; }
        if (len == 1) { return 1; }

        int res = 0;
        res += func3(s.substr(1));
        for (int l = len; l >= 1; l--) {
            res += isPalindromic(s.substr(0, l));
        }
        return res;
    }
    // ** recursive (top-down) and save palindromic result
    // ** into map, but supper slow.
    // ** I think the reason is string and unordered_map manipulaition 
    // ** cost more than O(n) palindormic compare.
    int func4(string s) {
        unordered_map<string, int> map;
        return helper4(s, map);
    }
    int helper4(string s, unordered_map<string, int>& map) {
        int len = s.length();
        if (len == 0) { return 0; }
        if (len == 1) { return 1; }

        int res = 0;
        res += helper4(s.substr(1), map);
        for (int l = len; l >= 1; l--) {
            res += isPalindromic(s.substr(0, l), map);
        }
        return res;
    }

    // ** helper functions
    void allSubString(string s, vector<string>& vec) {
        int len = s.length();
        if (len == 0) { 
            return;
        }
        if (len == 1) {
            vec.push_back(s);
            return;
        }
        allSubString(s.substr(1, len), vec);
        for (int l = len; l >= 1; l--) {
            vec.push_back(s.substr(0, l));
        }
        return;
    }
    int isPalindromic(string s) {
        int len = s.length();
        if (len <= 0) { return 0; }
        if (len == 1) { return 1; }

        int i = 0, j = len - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return 0;
            }
            i++;
            j--;
        }

        return 1;
    }
    int isPalindromic(string s, unordered_map<string, int>& map) {
        int len = s.length();
        if (len <= 0) { return 0; }
        if (len == 1) { return 1; }
        if (len == 2) { return s[0] == s[1] ? 1 : 0; }
        if (map.count(s) == 1) { return map[s]; }

        if (s[0] != s[len-1]) {
            map[s] = 0;
        } else {
            map[s] = isPalindromic(s.substr(1, len-2), map);
        }

        return map[s];
    }
    int isPalindromic(string s, int lo, int hi, vector<vector<int>>& vec) {
        if (lo > hi)  {  return 0; }
        if (lo < 0 || hi >= s.length()) { return 0; }
        if (vec[lo][hi] >= 0) { return vec[lo][hi]; }

        if (lo == hi) { // 1
            vec[lo][hi] = 1;
        } else if (hi - lo == 1) { // 2
            vec[lo][hi] = s[lo] == s[hi] ? 1 : 0;
        } else { // more
            if (s[lo] != s[hi]) {
                vec[lo][hi] = 0;
            } else {
                vec[lo][hi] = isPalindromic(s, lo+1, hi-1, vec);
            }
        }

        return vec[lo][hi];
    }

    // ** recursive (top-down) + memo, use 2-dimensional int array.
    int func5(string s) {
        int n = s.length();
        vector<vector<int>> vec;
        for (int i = 0; i < n; i++) {
            vector<int> row(n, -1);
            vec.push_back(row);
        }
        return helper5(s, 0, n-1, vec);
    }
    int helper5(string s, int lo, int hi, vector<vector<int>>& vec) {
        if (lo > hi)  { return 0; }
        if (lo == hi) { return 1; }

        int res = helper5(s, lo + 1, hi, vec);
        for (int i = hi; i >= lo; i--) {
            res += isPalindromic(s, lo, i, vec);
        }
        return res;
    }
    // ** recursive (top-down) + memo, use 2-dimensional int array.
    // ** !BUT! generate all sub strings while check is palindrome.
    int func6(string s) {
        int n = s.length();
        vector<vector<int>> marked(n);
        for (int i = 0; i < n; i++) {
            marked[i].assign(n, -1);
        }
        int res = 0;
        for (int end = n - 1; end >= 0; end--) {
            for (int start = 0; start <= end; start++) {
                res += isPalindromic(s, start, end, marked);
            }
        }
        return res;
    }
    // ** iterative + memo (bottom-up), fast
    int func7(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n);
        for (int i = 0; i < n; i++) {
            isPalin[i].assign(n, false);
        }
        int res = 0;
        // ** window size = 1
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
            res += 1;
        }
        // ** window size = 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                isPalin[i][i+1] = true;
                res += 1;
            }
        }
        // ** window size > 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPalin[i+1][j-1]) {
                    isPalin[i][j] = true;
                    res += 1;
                }
            }
        }

        return res;
    }
};

