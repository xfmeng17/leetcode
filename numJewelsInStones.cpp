class Solution {
public:
	/*
    int numJewelsInStones(string J, string S) {
    	bool upper[26] = {false};
    	bool lower[26] = {false};
    	for (int i = 0; i < J.length(); i++) {
    		if (isupper(J[i])) {
    			upper[J[i] - 'A'] = true;
    		} else {
    			lower[J[i] - 'a'] = true;
    		}
    	}
    	int cnt = 0;
    	for (int i = 0; i < S.length(); i++) {
    		if (isupper(S[i])) {
    			if (upper[S[i] - 'A']) cnt++;
    		} else {
    			if (lower[S[i] - 'a']) cnt++;
    		}
    	}
    	return cnt;
    }
    */

    // ref
    int numJewelsInStones(string J, string S) {
		int res = 0;
		set<char> jewelSet(J.begin(), J.end());
		for (char s : S) {
			if (jewelSet.count(s)) {
				res++;
			}
		}
		return res;
	}
};
