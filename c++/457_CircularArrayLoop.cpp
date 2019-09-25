class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        return func1(nums);
    }

    // straight forward O(n^2)
    bool func1(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> marked(n, -1);
    	for (int i = 0; i < n; i++) {
    		int cnt = 1;
    		bool right = nums[i] > 0 ? true : false;
    		marked[i] = i;

    		int next = i;
    		bool ret = false;
    		while (true) {
    			next = (next + nums[next]) % n;
    			if (next < 0) {
    				next += n;
    			}
    			if ((right && nums[next] < 0) ||
	    			(!right && nums[next] > 0)) {
	    			break;
	    		}
	    		if (marked[next] >= i) {
	    			if (next == i && cnt > 1) {
	    				ret = true;
	    			}
	    			break;
	    		}
	    		marked[next] = i;
	    		cnt++;
    		}
    		if (ret) return true;
    	}
    	return false;
    }
};