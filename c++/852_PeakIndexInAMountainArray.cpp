class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // return func1(A);
        return func2(A);
    }
    // ** simple search
    int func1(vector<int>& A) {
    	for (int i = 1; i < A.size() - 1; i++) {
    		if (A[i] > A[i-1] && A[i] > A[i + 1]) {
    			return i;
    		}
    	}
    	return -1;
    }
    // binary search
    int func2(vector<int>& A) {
    	int lo = 1;
    	int hi = A.size() - 2;
    	while (lo <= hi) {
    		int mid = (lo + hi) / 2;
    		if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
    			return mid;
    		} else if (A[mid] < A[mid - 1]) {
    			hi = mid - 1;
    		} else {
    			lo = mid + 1;
    		}
    	}
    	return -1;
    }
};