class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return func1(nums, target);
		return func2(nums, target);
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

	// 2019-10-07
	// 1. find rotate point
	// 2. find target in two segments divide by rotate point
	int func2(vector<int>& nums, int target) {
		int rotate = findRotate(nums);
		int index1 = binarySearch(nums, 0, rotate - 1, target);
		int index2 = binarySearch(nums, rotate, nums.size() - 1, target);

		if (index1 == -1 && index2 == -1) {
			return -1;
		}

		return index1 != -1 ? index1 : index2;
	}

	int findRotate(vector<int>& nums) {
		int lo = 0, hi = nums.size() - 1;

		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] > nums[hi]) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}

		return lo;
	}

	int binarySearch(vector<int>& nums, int lo, int hi, int target) {
		if (hi >= nums.size()) {
			return -1;
		}

		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		return -1;
	}
};
