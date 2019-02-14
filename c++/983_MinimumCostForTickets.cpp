class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return func1(days, costs);        
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
};
