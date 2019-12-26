class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> sum;
        int res = 0;
        sum.push_back(0);
        for (string s : ops) {
        	int i = sum.size();
        	if (s == "+") {
        		int n = sum.at(i - 1) + sum.at(i - 2);
        		res += n;
        		sum.push_back(n);
        	} else if (s == "D") {
        		int n = sum.at(i - 1) * 2;
        		res += n;
        		sum.push_back(n);
        	} else if (s == "C") {
        		int n = sum.at(i - 1);
        		res -= n;
        		sum.pop_back();
        	} else {
        		int n = stoi(s);
        		res += n;
        		sum.push_back(n);
        	}
        }
        return res;
    }
};
