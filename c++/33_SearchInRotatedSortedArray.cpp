class Solution {
public:
    int search(vector<int>& nums, int target) {
        return func1(nums, target);
    }

    // ** my straight forward solution
    // ** use binary search find min index
    int func1(vector<int>& nums, int target) {
    	int lo = 0, hi = nums.size() - 1;
    	while (lo < hi) {
    		int mid = (hi + lo) / 2;
    		if (nums[mid] > nums[hi]) {
    			lo = mid + 1;
    		} else {
    			hi = mid;
    		}
    	}
    	int rotate = lo;

    	lo = 0, hi = nums.size() - 1;
    	while (lo <= hi) {
    		int mid = (lo + hi) / 2;
    		int realmid = (mid + rotate) % nums.size();
    		if (nums[realmid] == target) {
    			return realmid;
    		} else if (nums[realmid] > target) {
    			hi = mid - 1;
    		} else {
    			lo = mid + 1;
    		}
    	}

    	return -1;
    }
};
