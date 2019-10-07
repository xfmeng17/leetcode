class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	// return func1(nums);
    	return func2(nums);
    }

    // ** dp[i] represents the LIS end at i
    int func1(vector<int>& nums) {
    	int N = nums.size();
    	if (N <= 0) return 0;

    	vector<int> dp(N, 1);

  		int res = 1;
    	for (int i = 1; i < N; i++) {
    		for (int j = i-1; j >= 0; j--) {
    			if (nums[i] > nums[j]) {
    				dp[i] = max(dp[i], 1 + dp[j]);
    			}
    		}
    		res = max(res, dp[i]);
    	}

    	return res;
    }

    // ** Reference, using a array called 'tails' to store
    // ** the smallest tail with the len of LIS which
    // ** may 1, 2, ..., N-1
    int func2(vector<int>& nums) {
    	int N = nums.size();
    	vector<int> tails(N+1, -1);

    	bool doPrint = false;
    	
    	int len = 1;
    	for (auto num : nums) {

            int lo = 1, hi = len;

    		if (doPrint) {
    			printf("beg: lo=%d, hi=%d\n", lo, hi);
    		}

    		while (lo < hi) {
    			int mid = (lo + hi) / 2;
    			if (tails[mid] < num) {
    				lo = mid + 1; 
    			} else {
    				hi = mid;
    			}
    		}
    		tails[lo] = num;

    		if (doPrint) {
    			printf("end: lo=%d, hi=%d\n", lo, hi);
    		}

    		if (lo == len) {
    			len++;
    		}

    		if (doPrint) {
    			for (int i = 0; i <= N; i++) {
	    			printf("length = %d with tail = %d\n", i, tails[i]);
	    		}
	    		printf("==========\n");
    		}
    		
    	}


    	return len - 1;
    }
};
