class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
     	return func1(price, special, needs);   
    }
    

    // ** straight forward DFS
    int func1(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    	return helper1(price, special, 0, needs);
    }
    int helper1(vector<int>& price,
    	vector<vector<int>>& special,
    	int specialIndex,
    	vector<int>& needs) {

    	if (special.size() <= specialIndex) {
    		int sum = 0;
    		for (int i = 0; i < needs.size(); i++) {
    			sum += needs[i] * price[i];
    		}
    		return sum;
    	}
    	// ** do not use special
    	int notSpecialCost = helper1(price, special, specialIndex+1, needs);
    	// ** use special
    	int useSpecialCost = notSpecialCost;
    	vector<int>& currSepcial = special[specialIndex];
    	bool canUseSpecial = true;
    	int cnt = 1;
    	while (canUseSpecial) {
    		vector<int> auxNeeds(needs.begin(), needs.end());
    		for (int i = 0; i < auxNeeds.size(); i++) {
    			auxNeeds[i] -= currSepcial[i] * cnt;
    			if (auxNeeds[i] < 0) {
    				canUseSpecial = false;
    				break;
    			}
    		}
    		if (canUseSpecial) {
    			useSpecialCost = min(useSpecialCost, currSepcial[currSepcial.size()-1] * cnt + 
    			helper1(price, special, specialIndex+1, auxNeeds));
    		}
    		cnt++;
    	}

    	return min(notSpecialCost, useSpecialCost);
    }
};
