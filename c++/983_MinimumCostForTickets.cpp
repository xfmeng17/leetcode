class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return func1(days, costs);
        return func2(days, costs);        
    }

    // ** 1. recursive top-down
    // ** Time Limit Exceeded
    int func1(vector<int>& days, vector<int>& costs) {
    	return helper1(days, costs, 0);
    }
    int helper1(vector<int>& days, vector<int>& costs, int index) {
    	if (days.size() <= index) {
    		return 0;
    	}

    	int dayIndex = index + 1;
    	while (dayIndex < days.size() && days[dayIndex] - days[index] < 1) {
    		dayIndex++;
    	}
    	int dayCost = costs[0] + helper1(days, costs, dayIndex);
    	
    	int wekIndex = index + 1;
    	while (wekIndex < days.size() && days[wekIndex] - days[index] < 7) {
    		wekIndex++;
    	}
    	int wekCost = costs[1] + helper1(days, costs, wekIndex);

    	int monIndex = index + 1;
    	while (monIndex < days.size() && days[monIndex] - days[index] < 30) {
    		monIndex++;
    	}
    	int monCost = costs[2] + helper1(days, costs, monIndex);

    	return min(dayCost, min(wekCost, monCost));
    }

    // ** 2. recursive+memo top-down
    // ** ac, time=8ms, space=9.5mb
    int func2(vector<int>& days, vector<int>& costs) {
    	vector<int> memo(days.size(), -1);
    	return helper2(days, costs, 0, memo);
    }
    int helper2(vector<int>& days, vector<int>& costs, int index, vector<int>& memo) {
    	if (days.size() <= index) {
    		return 0;
    	}
    	if (memo[index] > 0) {
    		return memo[index];
    	}

    	int dayIndex = index + 1;
    	while (dayIndex < days.size() && days[dayIndex] - days[index] < 1) {
    		dayIndex++;
    	}
    	int dayCost = costs[0] + helper2(days, costs, dayIndex, memo);
    	
    	int wekIndex = index + 1;
    	while (wekIndex < days.size() && days[wekIndex] - days[index] < 7) {
    		wekIndex++;
    	}
    	int wekCost = costs[1] + helper2(days, costs, wekIndex, memo);

    	int monIndex = index + 1;
    	while (monIndex < days.size() && days[monIndex] - days[index] < 30) {
    		monIndex++;
    	}
    	int monCost = costs[2] + helper2(days, costs, monIndex, memo);

    	memo[index] = min(dayCost, min(wekCost, monCost));
    	return memo[index];
    }
};
