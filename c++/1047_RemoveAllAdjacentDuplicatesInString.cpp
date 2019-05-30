class Solution {
public:
    string removeDuplicates(string S) {        
        // return func1(S);
        // return func2(S);
        return func3(S);
    }

    // ** string operation is really slow! 
    string func1(string S) {
        if (S.length() <= 1) {
            return S;
        }

        for (int i = 1; i < S.length(); i++) {
            if (S[i] == S[i-1]) {
                string head = i-1 > 0 ? S.substr(0, i-1) : "";
                string tail = i+1 < S.length() ? S.substr(i+1) : "";
                return func1(head + tail);
            }
        }
        return S;
    }
    
    string func2(string S) {
        int N = S.length();
        if (N <= 1) {
            return S;
        }

        stack<char> stk;
        for (int i = 0; i < N; i++) {
            if (stk.empty()) {
                stk.push(S[i]);
            } else {
                if (stk.top() == S[i]) {
                    stk.pop();
                } else {
                    stk.push(S[i]);
                }
            }
        }
        string res = "";
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // ** use vector
    string func3(string S) {
        int N = S.length();
        if (N <= 1) {
            return S;
        }

        vector<char> vec;
        for (int i = 0; i < N; i++) {
            if (vec.empty()) {
                vec.push_back(S[i]);
            } else {
                if (vec.back() == S[i]) {
                    vec.pop_back();
                } else {
                    vec.push_back(S[i]);
                }
            }
        }
        return string(vec.begin(), vec.end());
    }
};
