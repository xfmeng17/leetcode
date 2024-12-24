class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // return func1(amount, coins);
    return func2(amount, coins);
  }

  int func1(int amount, vector<int> &coins) {
    vector<int> kp(amount + 1, 0);
    kp[0] = 1;
    for (int i = 1; i <= coins.size(); i++) {
      for (int v = coins[i - 1]; v <= amount; v++) {
        kp[v] += kp[v - coins[i - 1]];
      }
    }
    return kp[amount];
  }

  // 2020-02-05, review
  int func2(int amount, vector<int> &coins) {
    int V = amount;
    vector<int> kp(V + 1, 0);
    kp[0] = 1;

    for (auto coin : coins) {
      completePack(kp, V, coin);
    }

    return kp[V];
  }

  void completePack(vector<int> &kp, int V, int cost) {
    for (int i = cost; i <= V; i++) {
      kp[i] += kp[i - cost];
    }
    return;
  }
};