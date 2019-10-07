class Solution {
public:
    int findLUSlength(string a, string b) {
    	if (a.compare(b) != 0) {
    		return max(a.length(), b.length());
    	}
    	return -1;
    }
};
