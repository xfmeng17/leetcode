class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        return func1(edges);
    }

    vector<int> func1(vector<vector<int>>& edges) {
        vector<int> ret;
        vector<int> union_find(edges.size()+1, 0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (union_find[u] == 0 && union_find[v] == 0) {
                union_find[u] = u;
                union_find[v] = u;
                continue;
            }
            if (union_find[u] != 0 && union_find[v] == 0) {
                union_find[v] = union_find[u];
                continue;
            }
            if (union_find[u] == 0 && union_find[v] != 0) {
                union_find[u] = union_find[v];
                continue;
            }
            if (union_find[u] != union_find[v]) {
                int val = union_find[v];
                for (int j = 0; j < union_find.size(); j++) {
                    if (union_find[j] == val) {
                        union_find[j] = union_find[u];
                    }
                }
                continue;
            }
            //** find
            ret.emplace_back(u);
            ret.emplace_back(v);
            break;
        }

        return ret;
    }

};