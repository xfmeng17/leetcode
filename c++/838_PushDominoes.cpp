class Solution {
public:
    string pushDominoes(string dominoes) {
    	return func1(dominoes);   
    }

    // ** two poniters
    string func1(string dominoes) {
    	int n = dominoes.length();
    	vector<int> right;
    	vector<int> left;

    	for (int i = 0; i < n; i++) {
    		if (dominoes[i] == 'L') {
				left.push_back(i);
    		} else if (dominoes[i] == 'R') {
    			right.push_back(i);
    		}
    	}

    	if (left.size() <= 0 && right.size() <= 0) {
    		return dominoes;
    	}
    	if (left.size() <= 0) {
    		for (int i = right[0]; i < n; i++) {
    			dominoes[i] = 'R';
    		}
    		return dominoes;
    	}
    	if (right.size() <= 0) {
    		for (int i = left.back(); i >= 0; i--) {
    			dominoes[i] = 'L';
    		}
    		return dominoes;
    	}

    	int lp = 0, rp = 0;
    	while (lp < left.size() && rp < right.size()) {
    		if (left[lp] < right[rp]) {
    			int lo = lp-1 >= 0 ? left[lp-1] : 0;
    			int hi = left[lp];
    			for (int i = hi; i >= lo; i--) {
    				dominoes[i] = 'L';
    			}
    			lp++;
    		} else {
    			int lo = right[rp];
    			while(rp < right.size() && right[rp] < left[lp]) {
    				rp++;
    			}
    			rp--;
    			int hi = right[rp];
    			for (int i = lo; i <= hi; i++) {
    				dominoes[i] = 'R';
    			}
    			int p1 = right[rp] + 1;
    			int p2 = left[lp] - 1;
    			while (p1 < p2) {
    				dominoes[p1++] = 'R';
    				dominoes[p2--] = 'L';
    			}
    			lp++;
    			rp++;
    		}
    	}

    	if (lp < left.size()) {
    		int lo = lp-1 >= 0 ? left[lp-1] : 0;
    		int hi = left.back();
    		for (int i = hi; i >= lo; i--) {
				dominoes[i] = 'L';
			}
    	}

    	if (rp < right.size()) {
    		int lo = right[rp];
    		int hi = dominoes.size() - 1;
    		for (int i = lo; i <= hi; i++) {
    			dominoes[i] = 'R';
    		}
    	}

    	return dominoes;
    }
};

