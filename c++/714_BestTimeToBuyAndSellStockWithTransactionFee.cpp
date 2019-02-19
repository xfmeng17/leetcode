class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
     	return func1(prices, fee);   
    }

    // ** 1. recursion, top-down, time-limit-exceeded
    int func1(vector<int>& prices, int fee) {
    	return helper1(prices, fee, 0, prices.size() - 1);
    }
    int helper1(vector<int>& prices, int fee, int lo, int hi) {
    	if (hi <= lo) {
    		return 0;
    	}
    	if (hi - lo == 1) {
    		return max(0, prices[hi] - prices[lo] - fee);
    	}

    	int ret = 0;
    	for (int i = lo; i < hi; i++) {
    		for (int j = i+1; j <= hi; j++) {
    			int p = prices[j] - prices[i] - fee;
    			int lf = helper1(prices, fee, lo, i-1);
    			int rt = helper1(prices, fee, j+1, hi);
    			ret = max(ret, lf + p + rt);
    		}
    	}

    	return ret;
    }

    // ** 2. 
};
