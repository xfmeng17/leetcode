class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> kp(amount+1, 0);
        kp[0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            for (int v = coins[i-1]; v <= amount; v++) {
                kp[v] += kp[v-coins[i-1]];
            }
        }
        return kp[amount];
    }
};