class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
    	vector<string> res;
        unordered_map<string, int> set;
        for (int i = 0; i < cpdomains.size(); i++) {
        	vector<string> vec_record = split(cpdomains[i], ' ');
        	int count = atoi(vec_record[0].c_str());
        	vector<string> vec_domain =  subdomain(vec_record[1], '.');
        	for (int j = 0; j < vec_domain.size(); j++) {
        		if (set.count(vec_domain[i]) <= 0) {
	        		set.insert({vec_domain[i], count});
	        	} else {
	        		set[vec_domain[i]] = set[vec_domain[i]] + count;
	        	}
        	}
        	
        }
        for (auto i = set.begin(); i != set.end(); i++) {
        	string str = to_string(i->second) + " " + i->first;
        	res.push_back(str);
        }

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

    	return res;
    }
    vector<string> subdomain(string domain, char del) {
    	vector<string> res;
    	int pos = 0;
    	res.push_back(domain);
    	while (pos < domain.length()) {
    		if (domain[pos] == del) {
    			domain = substr(pos + 1);
    			res.push_back(domain);
    			pos = 0;
    		}
    	}
    	if (domain != "") {
    		res.push_back(domain)
    	}
    	
    	return res;
    }
};