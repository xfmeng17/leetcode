class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
    	return func1(logs);
    }

    // ** straight forward
    static bool logCompare(string s1, string s2) {
    	string sub1 = s1.substr(s1.find(' ') + 1);
    	string sub2 = s2.substr(s2.find(' ') + 1);
    	return sub1 < sub2;
    }

    vector<string> func1(vector<string>& logs) {
    	queue<string> que;
    	vector<string> vec;
    	for (string s : logs) {
    		int p = s.find(' ');
    		if (p <= 0 || p >= s.length() - 1) {
    			continue;
    		}
    		if (isdigit(s[p+1])) {
    			que.push(s);
    		} else {
    			vec.push_back(s);
    		}
    	}
    	sort(vec.begin(), vec.end(), Solution::logCompare);
    	while(que.size() > 0) {
    		vec.push_back(que.front());
    		que.pop();
    	}
    	return vec;
    }
};
