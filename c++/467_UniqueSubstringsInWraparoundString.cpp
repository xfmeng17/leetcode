class Solution {
public:
	int findSubstringInWraproundString(string p) {
		return func1(p);
	}

	// ** wa, bad case: "zaba"
	// ** I double count "a" but "zab" already count a

	/* 	Update190325 use iteration with a vector to filter
		the substrings already exists.
		But WA the same cause can't solve circulation like this:
		"a..za...za...z"
	*/
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

		// int res = 0;
		// for (auto it = table.begin(); it != table.end(); it++) {
		// 	int len = (*it).length();
		// 	res += (1 + len) * len / 2;
		// }

		vector<string> list(table.begin(), table.end());
		vector<bool> find(table.size(), false);
		for (int i = 0; i < list.size(); i++) {
			for (int j = 0; j < list.size(); j++) {
				if (i == j) continue;
				if (list[j].find(list[i]) != string::npos) {
					find[i] = true;
					break;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < list.size(); i++) {
			// cout << list[i] << ": " << find[i] << endl;
			if (!find[i]) {
				int len = list[i].length();
				res += (1 + len) * len / 2;
			}
		}

		return res;
	}
};