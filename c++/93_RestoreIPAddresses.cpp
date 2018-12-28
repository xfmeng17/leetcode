class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	return func1(s);    
    }

    vector<string> func1(string s) {
    	vector<string> res = helper(s, 4);
    	return res;
    }

    bool check(string s) {
    	if (s.length() < 0 || s.length() > 3) {
    		return false;
    	}
    	if (s.length() == 2 && s[0] == '0') {
    		return false;
    	}
    	if (s.length() == 3 && (s[0] == '0' || stoi(s) > 255)) {
    		return false;
    	}
    	return true;
    }

    vector<string> helper(string str, int cnt) {
    	vector<string> res;
    	
    	if (str.length() < cnt) {
    		return res;
    	}

    	if (cnt == 1) {
    		if (check(str)) {
    			res.push_back(str);
    			return res;
    		}
    	}

    	if (cnt >= 2) {
    		// ** cut 1 as head
    		string h1 = str.substr(0, 1);
    		if (check(h1)) {
    			string r1 = str.substr(1);
	    		vector<string> sub = helper(r1, cnt - 1);
	    		if (sub.size() > 0) {
	    			for (string s : sub) {
	    				res.push_back(h1 + "." + s);
	    			}
	    		}
    		}
    		
    		// ** cut 2 as head
    		string h2 = str.substr(0, 2);
    		if (check(h2) && (str.length() >= cnt + 1)) {
    			string r2 = str.substr(2);
	    		vector<string> sub = helper(r2, cnt - 1);
	    		if (sub.size() > 0) {
	    			for (string s : sub) {
	    				res.push_back(h2 + "." + s);
	    			}
	    		}
    		}
    		
    		// ** cut 3 as head
    		string h3 = str.substr(0, 3);
    		if (check(h3) && (str.length() >= cnt + 2)) {
    			string r3 = str.substr(3);
	    		vector<string> sub = helper(r3, cnt - 1);
	    		if (sub.size() > 0) {
	    			for (string s : sub) {
	    				res.push_back(h3 + "." + s);
	    			}
	    		}
    		}
    	}

    	return res;
    }
};
