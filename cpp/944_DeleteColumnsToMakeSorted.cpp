class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // return func1(A);
        return func2(A);
    }

    // ** straight forward way
    int func1(vector<string>& A) {
    	if (A.size() <= 0 || A[0].length() <= 0) {
    		return 0;
    	}
    	int res = A[0].length();
    	for (int j = 0; j < A[0].length(); j++) {
    		bool nondes = true;
    		for (int i = 0; i < A.size() - 1; i++) {
    			if (A[i][j] > A[i+1][j]) {
    				nondes = false;
    				break;
    			}
    		}
    		if (nondes) { res--; }
    	}
    	return res;
    }
    // ** same as func1 but more concise
    int func2(vector<string>& A) {
    	if (A.size() <= 0 || A[0].length() <= 0) {
    		return 0;
    	}
    	int res = A[0].length();
    	for (int j = 0; j < A[0].length(); j++) {
    		int i = 0;
    		for (; i < A.size() - 1; i++) {
    			if (A[i][j] > A[i+1][j]) {
    				break;
    			}
    		}
    		if (i == A.size() - 1) { res--; }
    	}
    	return res;
    }
};
