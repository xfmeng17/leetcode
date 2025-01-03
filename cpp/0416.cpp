class Solution {
public:
  bool canPartition(vector<int> &nums) {
    // return func1(nums);
    // return func2(nums);
    // return func3(nums);
    return func4(nums);
  }
  // Recursive
  bool func1(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    if (sum % 2 == 1) {
      return false;
    }
    int target = sum / 2;

    return helper1(nums, 0, target);
  }
  bool helper1(vector<int> &nums, int i, int target) {
    if (i >= nums.size()) {
      return false;
    }
    if (target == 0) {
      return true;
    }

    int pick = helper1(nums, i + 1, target - nums[i]);
    int notp = helper1(nums, i + 1, target);

    return pick || notp;
  }

  // 0/1 knapsack problem
  bool func2(vector<int> &nums) {
    int sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    if (sum & 1) {
      return false;
    }
    sum /= 2;
    int n = nums.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
      dp[i][0] = true;
    }
    for (int j = 1; j <= sum; j++) {
      dp[0][j] = false;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j - nums[i - 1] >= 0) {
          dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i - 1]]);
        }
      }
    }

    return dp[n][sum];
  }

  // Use 1-dimension
  // Amazing implement
  bool func3(vector<int> &nums) {
    int sum = 0;
    for (auto n : nums) {
      sum += n;
    }
    if (sum & 1) {
      return false;
    }
    sum /= 2;

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int i = 1; i <= nums.size(); i++) {
      for (int j = sum; j > 0; j--) {
        if (j - nums[i - 1] >= 0) {
          dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
      }
    }

    return dp[sum];
  }

  // 2020-02-05 review
  bool func4(vector<int> &nums) {
    if (nums.size() <= 0) {
      return false;
    }

    int V = 0;
    for (auto n : nums) {
      V += n;
    }
    if (V & 1 == 1) {
      return false;
    }

    V /= 2;
    vector<bool> kp(V + 1);
    kp[0] = true;

    for (int i = 0; i < nums.size(); i++) {
      zeroOnePack(kp, V, nums[i]);
    }

    return kp[V];
  }
  void zeroOnePack(vector<bool> &kp, int V, int cost) {
    for (int i = V; i >= cost; i--) {
      kp[i] = kp[i] || kp[i - cost];
    }
    return;
  }
};
