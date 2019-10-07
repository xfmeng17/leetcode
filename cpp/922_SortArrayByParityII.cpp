class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int eve = 0;
        int odd = 1;
        int size = A.size();
        while (eve < size && odd < size) {
        	while (eve < size && A[eve] % 2 == 0) { eve += 2; }
        	while (odd < size && A[odd] % 2 == 1) { odd += 2; }
        	if (eve < size && odd < size) {
        		int temp = A[eve];
        		A[eve] = A[odd];
        		A[odd] = temp;
        		eve += 2;
        		odd += 2;
        	}
        }
        return A;
    }
};