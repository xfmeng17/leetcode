class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> path(n, vector<int>(n, distanceThreshold+1));
        for (int i = 0; i < n; i++) {
            path[i][i] = 0;
        }
        for (int i = 0; i < edges.size(); i++) {
            int lo = edges[i][0];
            int hi = edges[i][1];
            int val = edges[i][2];
            path[lo][hi] = val;
            path[hi][lo] = val;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (path[i][j] > path[i][k] + path[k][j]) {
                        path[i][j] = path[i][k] + path[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // printf("path[%d][%d]=%d\n", i, j, path[i][j]);
            }
        }
        int min_idx = 0;
        int min_val = distanceThreshold + 1;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < n; j++) {
                if (path[i][j] <= distanceThreshold) {
                    val++;
                }
            }
            if (val <= min_val) {
                min_val = val;
                min_idx = i;
            }
        }
        return min_idx;
    }
};