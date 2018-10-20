class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> res(A[0].size());
        for (int i = 0; i < A.size(); i++) {
        	for (int j = 0; j < A[i].size(); j++) {
        		res[j].push_back(A[i][j]);
        	}
        }
        return res;
    }
};