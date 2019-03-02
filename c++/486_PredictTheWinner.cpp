class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	// ** even size, same to Stone Game, always return true.
        if (nums.size() % 2 == 0) {
        	return true;
        }
        // ** odd size, new dp problem
        return func1(nums);
    }

    bool func1(vector<int>& nums) {
    	// TODO
    }
    void helper1(vector<int>& nums, int lo, int hi, bool turn) {
    }
};
