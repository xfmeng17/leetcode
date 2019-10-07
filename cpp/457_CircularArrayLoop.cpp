class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        // return func1(nums);
        // return func2(nums);
        return func3(nums);
    }

    // Straight forward time: O(n^2), space O(n)
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

    // Use another vector count reduce time to O(n)
    bool func2(vector<int>& nums) {
    	int N = nums.size();
    	vector<int> marked(N, -1);
    	vector<int> count(N, 0);
    	for (int i = 0; i < N; i++) {
    		bool right = nums[i] > 0 ? true : false;
    		int cnt = 1;
    		
    		marked[i] = i;
    		count[i] = cnt;
    		int next = i;
    		while (true) {
    			next = (next + nums[next]) % N;
    			if (next < 0) {
    				next += N;
    			}
    			if ((right && nums[next] < 0) ||
	    			(!right && nums[next] > 0)) {
	    			break;
	    		}
	    		if (marked[next] == i) {
	    			if (cnt - count[next] > 1) {
	    				return true;
	    			}
	    			break;
	    		}
	    		cnt++;
	    		marked[next] = i;
	    		count[next] = cnt;
    		}
    	}
    	return false;
    }

    // Upgrate func2() to only use O(1) space
    bool func3(vector<int>& nums) {
    	const int MAX = 20000;
    	int N = nums.size();
    	for (int i = 0; i < N; i++) {
    		bool positive = nums[i] > 0 ? true : false;
    		int next = i;

    		while (nums[next] < MAX) {
    			int prev = next;
    			next = (next + nums[next]) % N;
    			next = next < 0 ? next + N : next;
    			nums[prev] = MAX + i;
                
    			if ((positive && nums[next] < 0) ||
    				(!positive && nums[next] > 0 && nums[next] < MAX)) {
    				break;
    			}
    			if (nums[next] >= MAX) {
    				if (prev != next && nums[next] == MAX + i) {
    					return true;
    				}
    				break;
    			}
    		}
    	}
    	return false;
    }
};