class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	// return func1(A, B);
    	return func2(A, B);
    }

    // ** two 1D array dp
    // ** dp1 means no swap i, dp2 means swap i
    int func1(vector<int>& A, vector<int>& B) {
    	int N = A.size();
    	vector<int> dp1(N, N + 1);
    	vector<int> dp2(N, N + 1);

    	dp1[0] = 0;
    	dp2[0] = 1;

    	for (int i = 1; i < N; i++) {
    		// ** no swap
    		if (A[i] > A[i-1] && B[i] > B[i-1]) {
    			dp1[i] = min(dp1[i], dp1[i-1]);
    		}
    		if (A[i] > B[i-1] && B[i] > A[i-1]) {
    			dp1[i] = min(dp1[i], dp2[i-1]);
    		}
    		// ** do swap
    		if (B[i] > A[i-1] && A[i] > B[i-1]) {
    			dp2[i] = min(dp2[i], dp1[i-1] + 1);
    		}
    		if (A[i] > A[i-1] && B[i] > B[i-1]) {
    			dp2[i] = min(dp2[i], dp2[i-1] + 1);
    		}
    		// cout<<"i="<<i<<", dp1="<<dp1[i]<<", dp2="<<dp2[i]<<endl;
    	}

    	return min(dp1[N-1], dp2[N-1]);
    }

    // ** four variables dp
    int func2(vector<int>& A, vector<int>& B) {
    	int N = A.size();

    	int pre1 = 0;
    	int pre2 = 1;
    	for (int i = 1; i < N; i++) {
    		int cur1 = N + 1;
    		int cur2 = N + 1;
    		if (A[i] > A[i-1] && B[i] > B[i-1]) {
    			cur1 = min(cur1, pre1);
    		}
    		if (B[i] > A[i-1] && A[i] > B[i-1]) {
    			cur1 = min(cur1, pre2);
    		}
    		if (A[i] > B[i-1] && B[i] > A[i-1]) {
    			cur2 = min(cur2, 1 + pre1);
    		}
    		if (A[i] > A[i-1] && B[i] > B[i-1]) {
    			cur2 = min(cur2, 1 + pre2);
    		}
    		pre1 = cur1;
    		pre2 = cur2;
    	}

    	return min(pre1, pre2);
    }
};
