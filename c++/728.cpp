class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
    	vector<int> res;
        for (int curr = left; curr <= right; curr++) {
        	int temp = curr;
        	bool flag = true;
        	while (temp > 0) {
        		int digit = temp % 10;
        		temp /= 10;
        		if (digit == 0 || curr % digit != 0) {
        			flag = false;
        			break;
        		}
        	}
        	if (flag) { res.push_back(curr); }
        }
        return res;
    }
};