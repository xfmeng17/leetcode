class Solution {
public:
    vector<string> letterCasePermutation(string S) {
    	return func1(S);
    }

    vector<string> func1(string S) {
    	vector<string> res;
    	helper1(S, 0, S.length(), res);
    	return res;
    }
    void helper1(string S, int i, int N, vector<string>& res) {
    	if (i >= N) {
    		if (N > 0 && res.isEmpty()) {
    			res.push_back(S);
    		}
    		return;
    	}
    	if (!isalpha(S[i])) {
    		helper1(S, i+1, N, res);
    		return;
    	}
    	string s1 = S;
    	string s2 = S;
    	if (islower(S[i])) {
    		toupper(s2[i]);
    	} else {
    		tolower(s2[i]);
    	}
    	res.push_back(s1);
    	res.push_back(s2);
    	helper1(S, i+1, N, res);
    }
};