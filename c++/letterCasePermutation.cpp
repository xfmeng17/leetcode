class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		// return func1(S);
		return func2(S);
	}

	// bitwise generate sequence
    vector<string> func1 (string S) {
    	int nums = 0;
    	vector<int> pos;
    	vector<string> ans;
    	for (int i = 0; i < S.length(); i++) {
    		if (isalpha(S[i])) {
    			nums++;
    			pos.push_back(i);
    		}
    	}
    	for (int seed = 0; seed < pow(2, nums); seed++) {
    		string t = S;
    		int s = seed;
    		for (int i = 0; i < nums; i++) {
    			if (s & 1) {
    				t[pos[i]] = reversal(t[pos[i]]);
    			}
    			s = s >> 1;
    		}
    		ans.push_back(t);
    	}
    	return ans;
    }

    // ref: back-track
    // so amazing to tog case using s[i] ^= (1 << 5)
    vector<string> func2 (string S) {
    	vector<string> ans;
    	backtrack(S, 0, ans);
    	return ans;
    }
    void backtrack(string &s, int i, vector<string> &ans) {
    	if (i == s.length()) {
    		ans.push_back(s);
    		return;
    	}
    	if (isalpha(s[i])) {
    		s[i] ^= (1 << 5);
    		backtrack(s, i + 1, ans);
    		s[i] ^= (1 << 5);
    	}
    	backtrack(s, i + 1, ans);
    }
    
    // helper functions
    char reversal(char c) {
    	if (isupper(c)) {
    		return tolower(c);
    	} else if (islower(c)) {
    		return toupper(c);
    	} else {
    		return c;
    	}
    }
};
