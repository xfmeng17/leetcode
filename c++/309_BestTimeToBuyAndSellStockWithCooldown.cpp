class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // return func1(prices);
        return func2(prices);
    }

    // ** recursive
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

    // recursive + memoization
    int func2(vector<int>& prices) {
        vector<int> buy(prices.size(), 0);
        vector<int> sel(prices.size(), 0);
        return helper2(prices, 0, 'b', buy, sel);
    }

    int helper2(vector<int>& prices, int i, char op,
        vector<int>& buy, vector<int>& sel) {
        
        if (i >= prices.size()) {
            return 0;
        }

        int res = 0;
        if (op == 'b') {
            res = max(res, helper2(prices, i+1, 'b', buy, sel));
            if (buy[i] == 0) {
                buy[i] = helper2(prices, i+1, 's', buy, sel) - prices[i];
            }
            res = max(res, buy[i]);
        } else {
            res = max(res, helper2(prices, i+1, 's', buy, sel));
            if (sel[i] == 0) {
                sel[i] = helper2(prices, i+2, 'b', buy, sel) + prices[i];
            }
            res = max(res, sel[i]);
        }

        return res;
    }
};
