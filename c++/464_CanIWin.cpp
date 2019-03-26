class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        return func1(maxChoosableInteger, desiredTotal);
    }

    // ** backtracking
    bool func1(int maxChoosableInteger, int desiredTotal) {
    	vector<bool> used(maxChoosableInteger+1, false);
    	if (desiredTotal <= 0) {
    		return true;
    	}
    	return helper1(maxChoosableInteger, desiredTotal, 1, used);
    }

    bool helper1(int maxChoosableInteger, int desiredTotal,
    	int player, vector<bool>& used) {

    	if (desiredTotal <= 0) {
    		return player == 2;
    	}

    	int currPlayer = player == 1 ? 2 : 1;
    	if (player == 1) {
    		bool res = true;
    		for (int i = 1; i <= maxChoosableInteger; i++) {
	    		if (!used[i]) {
	    			used[i] = true;
	    			res &= helper1(maxChoosableInteger, desiredTotal - i, currPlayer, used);
	    			used[i] = false;
	    		}
	    	}
	    	return res;
    	} else {
    		bool res = false;
	    	for (int i = 1; i <= maxChoosableInteger; i++) {
	    		if (!used[i]) {
	    			used[i] = true;
	    			res |= helper1(maxChoosableInteger, desiredTotal - i, currPlayer, used);
	    			used[i] = false;
	    		}
	    	}
	    	return res;
    	}
    }
};