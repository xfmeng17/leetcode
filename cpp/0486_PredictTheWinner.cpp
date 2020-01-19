class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    // ** even size, same to Stone Game, always return true.
    if (nums.size() % 2 == 0) {
      return true;
    }
    // ** odd size, new dp problem
    // return func1(nums);
    return func2(nums);
  }

  bool func1(vector<int> &nums) {
    int sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    int play1 = helper1(nums, sum, 0, nums.size() - 1);
    int play2 = sum - play1;

    return play1 >= play2;
  }
  int helper1(vector<int> &nums, int sum, int lo, int hi) {
    if (lo > hi)
      return 0;

    int lfSum = sum - nums[lo];
    int lfRet = nums[lo] + (sum - helper1(nums, lfSum, lo + 1, hi));
    int rtSum = sum - nums[hi];
    int rtRet = nums[hi] + (sum - helper1(nums, rtSum, lo, hi - 1));

    return max(lfRet, rtRet);
  }

  bool func2(vector<int> &nums) {
    int sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
    int play1 = helper2(nums, sum, 0, nums.size() - 1, memo);
    int play2 = sum - play1;

    return play1 >= play2;
  }
  int helper2(vector<int> &nums, int sum, int lo, int hi,
              vector<vector<int>> &memo) {
    if (lo > hi)
      return 0;
    if (memo[lo][hi] >= 0)
      return memo[lo][hi];

    int lfSum = sum - nums[lo];
    int lfRet = nums[lo] + (sum - helper1(nums, lfSum, lo + 1, hi));
    int rtSum = sum - nums[hi];
    int rtRet = nums[hi] + (sum - helper1(nums, rtSum, lo, hi - 1));

    memo[lo][hi] = max(lfRet, rtRet);

    return memo[lo][hi];
  }
};
