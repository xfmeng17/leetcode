func maxProfit(prices []int) int {
	if len(prices) <= 0 {
		return 0;
	}
	
	ret := 0;
	lo, hi := 0, 0;
	for i := 0; i < len(prices); i++ {
		if prices[i] > prices[hi] {
			hi = i;
		} else {
			ret += prices[hi] - prices[lo];
			lo = i;
			hi = i;
		}
	}
	return ret + (prices[hi] - prices[lo]);
}