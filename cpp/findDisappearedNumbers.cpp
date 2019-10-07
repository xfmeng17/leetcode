class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	// return func1(nums);
    	return func2(nums);
    }

    // Trick to understand why this is O(n)
    vector<int> func1(vector<int>& nums) {
    	int i = 0;
		while (i < nums.size()) {
			while (nums[i] != (i + 1)) {
				if (nums[nums[i] - 1] != nums[i]) {
					int temp = nums[nums[i] - 1];
					nums[nums[i] - 1] = nums[i];
					nums[i] = temp;
				} else {
					break;
				}
			}
			i++;
		}
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != (i + 1)) {
				ans.push_back(i + 1);
			}
		}
		return ans;
    }

    // ref
    vector<int> func2(vector<int>& nums) {
    	for (int i = 0; i < nums.size(); i++) {
    		int k = abs(nums[i]) - 1;
    		if (nums[k] > 0) {
    			nums[k] = -nums[k];
    		}
    	}
    	vector<int> ans;
    	for (int i = 0; i < nums.size(); i++) {
    		if (nums[i] > 0) {
    			ans.push_back(i + 1);
    		}
    	}
    	return ans;
    }
};
