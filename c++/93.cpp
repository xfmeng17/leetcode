class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	return func1(s);    
    }

    vector<string> func1(string s) {
    	vector<string> res;

    	return res;
    }

    bool check(string s) {
    	if (s.size() < 0 || s.size() > 3) {
    		return false;
    	}
    	if (s.size() == 2 && s[0] == '0') {
    		return false;
    	}
    	if (s.size() == 3 && (s[0] == '0' || atoi(s) > 255)) {
    		return false;
    	}
    	return true;
    }
    vector<string> helper(string str, int cnt) {
    	vector<string> res;
    	if (cnt == 1) {
    		res.push_back(str);
    		return res;
    	}
    	if (cnt == 2) {
    		
    	}
    }
};
