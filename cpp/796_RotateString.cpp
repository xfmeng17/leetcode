class Solution {
public:
    bool rotateString(string A, string B) {
        // return func1(A, B);
        return func2(A, B);
    }

    bool func1(string A, string B) {
    	if (A == B) {
    		return true;
    	}
        for (int i = 0; i < A.length(); i++) {
        	A = A.substr(1) + A[0];
        	if (A == B) {
        		return true;
        	}
        }
        return false;
    }

    // ** reference
    bool func2(string A, string B) {
    	return A.length() == B.length() && (A + A).find(B) != -1;
    }
};