class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // return func1(prices);
    // return func2(prices);
    return func3(prices);
  }
  // ** O(n^2)
  int func1(vector<int> &prices) {
    int max = 0;
    for (int i = 0; i < prices.size(); i++) {
      for (int j = i + 1; j < prices.size(); j++) {
        if (prices[j] - prices[i] > max) {
          max = prices[j] - prices[i];
        }
      }
    }
    return max;
  }

  // ** O(n)
  int func2(vector<int> &prices) {
    if (prices.size() <= 0) {
      return 0;
    }
    int maxProfit = 0;
    int minPrice = prices[0];
    for (int i = 0; i < prices.size(); i++) {
      minPrice = min(minPrice, prices[i]);
      maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
  }

  int func3(vector<int> &prices) {
    int maxProfit = 0;
    int minIndex = 0;
    for (int i = 0; i < prices.size(); i++) {
      minIndex = prices[i] < prices[minIndex] ? i : minIndex;
      maxProfit = max(maxProfit, prices[i] - prices[minIndex]);
    }
    return maxProfit;
  }
};