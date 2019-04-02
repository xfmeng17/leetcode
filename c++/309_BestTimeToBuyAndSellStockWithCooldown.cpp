class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return func1(prices);
    }

    int func1(vector<int>& prices) {
        return helper1(prices, 0, 'b');
    }

    int helper1(vector<int>& prices, int i, char op) {
        if (i >= prices.size()) {
            return 0;
        }

        int res = 0;
        if (op == 'b') {
            res = max(res, helper1(prices, i+1, 'b'));
            res = max(res, helper1(prices, i+1, 's') - prices[i]);
        } else if (op == 's') {
            res = max(res, helper1(prices, i+1, 's'));
            res = max(res, helper1(prices, i+2, 'b') + prices[i]);
        }

        return res;
    }
};
