class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // return func1(coins, amount);
    return func2(coins, amount);
  }

  // ** standard completely 0/1 knapsack
  int func1(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (auto coin : coins) {
      for (int i = 0; i <= amount; i++) {
        if (i - coin >= 0) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] < amount + 1 ? dp[amount] : -1;
  }

  // Update at 2020-01-24 use same code style
  // Same problem to 528
  int func1(vector<int> &coins, int amount) {
    vector<int> kp(amount+1, amount+1);
    kp[0] = 0;

    for (int i = 1; i <= coins.size(); i++) {
      for (int v = coins[i-1]; v <= amount; v++) {
        kp[v] = min(kp[v], 1 + kp[v-coins[i-1]]);
      }
    }

    return kp[amount] < amount+1 ? kp[amount] : -1;
  }
};