class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    	return func1(cost, 0);   
    }
	
	int func1(vector<int>& cost, int i) {
		if (i >= cost.size()) {
			return 0;
		}
		if (i == cost.size() - 1) {
			return cost[i];
		}
		int one = cost[i] + func1(cost, i + 1);
		int two = one;
		if (i < cost.size() - 2) {
			two = cost[i + 1] + func1(cost, i + 2);
		}
		return min(one, two);
	}    
};
