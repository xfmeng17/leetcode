class Solution {
public:
    int findSubstringInWraproundString(string p) {
    	return func1(p);
    }

    // ** wa, bad case: "zaba"
    // ** I double count "a" but "zab" already count a
    int func1(string p) {
    	unordered_set<string> table;

    	int lo = 0;
    	int hi = 1;
    	while (hi < p.length()) {
    		int diff = (p[hi] + 26 - p[hi-1]) % 26;
    		if (diff == 1) {
    			hi++;
    		} else {
    			string s = p.substr(lo, hi - lo);
    			if (table.count(s) <= 0) {
    				table.insert(s);
    			}
    			lo = hi;
    			hi++;
    		}
    	}
    	string s = p.substr(lo, hi - lo);
		if (table.count(s) <= 0) {
			table.insert(s);
		}

		int res = 0;
		for (auto it = table.begin(); it != table.end(); it++) {
			int len = (*it).length();
			res += (1 + len) * len / 2;
		}

		return res;
    }
};