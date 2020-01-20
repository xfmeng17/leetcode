class Solution {
public:
  bool checkSubarraySum(vector<int> &nums, int k) {
    // return func1(nums, k);
    return func2(nums, k);
  }

  // ** dp[i] = sum nums from 0 to i
  // ** Time O(N^2), space O(N)
  bool func1(vector<int> &nums, int k) {
    int N = nums.size();
    if (N <= 1) {
      return false;
    }

    vector<int> dp(N, 0);
    dp[0] = nums[0];
    for (int i = 1; i < N; i++) {
      dp[i] = nums[i] + dp[i - 1];
    }

    for (int len = N; len >= 2; len--) {
      for (int lo = 0, hi = len - 1; hi < N; lo++, hi++) {
        int subSum = dp[hi] - dp[lo] + nums[lo];
        if (k == 0) {
          if (subSum == 0) {
            return true;
          }
        } else {
          if (subSum % k == 0) {
            return true;
          }
        }
      }
    }

    return false;
  }

  /* Reference, math! find the mod that repeats
   *
   * If we find that a running sum value at index j
   * has been previously seen before in some earlier
   * index i, then we know the sub-array (i, j] contains
   * a desired sum.
   *
   * Pay attention the index of initial sum=0 is -1
   */

  bool func2(vector<int> &nums, int k) {
    int N = nums.size();
    if (N <= 1) {
      return false;
    }

    if (k == 0) {
      for (int i = 0; i < N - 1; i++) {
        if (nums[i] == 0 && nums[i + 1] == 0) {
          return true;
        }
      }
      return false;
    }

    unordered_map<int, int> map;

    // ** the index of sum=0 is -1
    map[0] = -1;

    int sum = 0;
    for (int i = 0; i < N; i++) {
      sum += nums[i];
      sum %= k;
      if (map.count(sum) > 0) {
        if (i - map[sum] >= 2) {
          return true;
        }
      } else {
        map[sum] = i;
      }
    }

    return false;
  }
};
