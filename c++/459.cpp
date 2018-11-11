class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		int sublen = s.length() / 2;
		for (sublen; sublen >= 1; sublen--) {
			if (s.length() % sublen != 0) { continue; }
			bool ok = true;
			for (int sec = 1; sec < s.length() / sublen && ok; sec++) {
				for (int i = 0; i < sublen; i++) {
					if (s[i] != s[i + sec * sublen]) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				return true;
			}
		}
		return false;
    }
};
