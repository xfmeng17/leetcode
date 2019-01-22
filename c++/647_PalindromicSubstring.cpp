class Solution {
public:
    int countSubstrings(string s) {
        // return func1(s); 
        // return func2(s);
        return func3(s);
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
    
    
};

