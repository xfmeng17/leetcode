class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
    	vector<string> res;
        unordered_map<string, int> set;
        vector<string> subdomins = split(cpdomains[0], ' ');
        // for (int i = 0; i < cpdomains.size(); i++) {
        // 	cout << cpdomains[i] << endl;
        // }
        return res;
    }

    vector<string> split(string str, char del) {
    	vector<string> res;
    	int pos = 0;
    	int len = 0;
    	while (pos < str.length()) {
    		if (str[pos] == del) {
    			res.push_back(str.substr(pos - len, len));
    			len = 0;
    		} else {
    			len++;
    		}
    		pos++;
    	}
    	res.push_back(str.substr(pos - len));

    	for (int i = 0; i < res.size(); i++) {
    		cout << res[i] << endl;
    	}
    	return res;
    }
};