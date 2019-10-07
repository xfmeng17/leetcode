class Solution {
public:
    int rob(vector<int>& nums) {
        return func1(nums);
    }
    /*
    * basic dp:
    * R(n) means MUST rob the n-th house and get most money,
    * from rob house 0 to n.
    * M(n) means get most money, So the fomule:
    * R(n) = nums[n] + M(n-2); (if rob house n then must not rob house n-1)
    * M(n) = Max { M(n-1), R(n) }; (1. not rob house n or 2. rob house n)
    */
    int func1(vector<int>& nums) {
    	if (nums.size() <= 0) return 0;

    	int n = nums.size();
    	vector<int> maxVec(n);
    	vector<int> robVec(n);

    	robVec[0] = nums[0];
    	robVec[1] = nums[1];
    	maxVec[0] = nums[0];
    	maxVec[1] = max(nums[0], nums[1]);
    	for (int i = 2; i < n; i++) {
    		robVec[i] = nums[i] + maxVec[i-2];
    		maxVec[i] = max(maxVec[i-1], robVec[i]);
    	}

    	return maxVec[n-1];
    }
};
