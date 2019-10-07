class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string res = "";

		if (strs.size() <= 0) {
			return "";			
		}
		if (strs.size() == 1) {
			return strs[0];
		}

		string base = strs[0];
		for (int i = 0; i < base.length(); i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (strs[j].size() <= i || base[i] != strs[j][i]) {
					return res;
				}
			}
			res += base[i];
		}

		return res;
    }
};
