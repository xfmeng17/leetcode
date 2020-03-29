class Solution {
public:
    int numTeams(vector<int>& rating) {
      	return func1(rating);
    }

    int func1(vector<int>& rating) {
    	int ret = 0;
    	for (int i = 0; i < rating.size(); i++) {
    		for (int j = i+1; j < rating.size(); j++) {
    			for (int k = j+1; k < rating.size(); k++) {
    				if (check(rating, i, j, k) == true) {
    					ret++;
    				}
    			}
    		}
    	}
    	return ret;
    }
    bool check(vector<int>& rating, int i, int j, int k) {
    	bool ret = false;
    	if (rating[i] > rating[j] && rating[j] > rating[k]) {
    		return true;
    	}
    	if (rating[i] < rating[j] && rating[j] < rating[k]) {
    		return true;
    	}
    	return false;
    }
};