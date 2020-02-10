class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int, int>> cnt;
        
        for (int i = 0; i < mat.size(); i++) {
            int n = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    n++;
                } else {
                    break;
                }
            }
            cnt.push_back(make_pair(i, n));
        }
        
        sort(cnt.begin(), cnt.end(), [](auto a, auto b){
            if (a.second < b.second) {
                return true;
            } else if (a.second > b.second) {
                return false;
            }
            return a.first < b.first;
        });
        
        for (int i = 0; i < k; i++) {
            res.push_back(cnt[i].first);
        }
        
        return res;
    }
};
