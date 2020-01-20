class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    // return func1(nums);
    // return func2(nums);
    // return func3(nums);
    return func4(nums);
  }
  /*
   * basic dp
   * S(n, m) = Sum of nums[n] to nums[m]
   * Memory Limit Exceeded
   */
  int func1(vector<int> &nums) {
    int n = nums.size();
    if (n <= 0)
      return 0;

    int res = nums[0];
    vector<vector<int>> memo(n);
    for (int i = 0; i < n; i++) {
      memo[i].resize(n);
      for (int j = 0; j < n; j++) {
        if (i == j) {
          memo[i][j] = nums[i];
        } else {
          memo[i][j] = memo[i][j - 1] + nums[j];
        }
        res = max(res, memo[i][j]);
      }
    }

    return res;
  }
  // ** trim space dp, O(n^2) time
  int func2(vector<int> &nums) {
    if (nums.size() <= 0)
      return 0;

    int n = nums.size();
    int res = nums[0];
    for (int i = 0; i < n; i++) {
      int acc = 0;
      for (int j = i; j < n; j++) {
        acc += nums[j];
        res = max(res, acc);
      }
    }

    return res;
  }

  // ** O(n) time
  int func3(vector<int> &nums) {
    int res = nums[0];
    int pre = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      cout << "pre = " << pre << endl;
      if (pre < 0) {
        pre = nums[i];
      } else {
        pre += nums[i];
      }
      res = max(res, pre);
    }
    return res;
  }

  // ** use hint, D&C
  int func4(vector<int> &nums) { return helper4(nums, 0, nums.size() - 1); }
  int helper4(vector<int> &nums, int lo, int hi) {
    if (lo > hi)
      return 0;
    if (lo == hi)
      return nums[lo];

    int mid = (lo + hi) / 2;
    int left = helper4(nums, lo, mid);
    int right = helper4(nums, mid + 1, hi);
    int cross = maxCrossingSum(nums, lo, hi, mid);

    return max(left, max(right, cross));
  }
  int maxCrossingSum(vector<int> &nums, int lo, int hi, int mid) {
    int sum = 0;
    int leftMax = nums[mid];
    for (int i = mid; i >= lo; i--) {
      sum += nums[i];
      leftMax = max(leftMax, sum);
    }
    sum = 0;
    int rightMax = nums[mid + 1];
    for (int i = mid + 1; i <= hi; i++) {
      sum += nums[i];
      rightMax = max(rightMax, sum);
    }
    return leftMax + rightMax;
  }

  // ** 2019-04-24 as-short-as-possible
  int func5(vector<int> &nums) {
    int pre = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (pre < 0) {
        pre = nums[i];
      } else {
        pre += nums[i];
      }
      res = max(res, pre);
    }
    return res;
  }
};
