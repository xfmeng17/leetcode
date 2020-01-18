//** 1. Quick-find, O(1) find, 0(n) union
class UF1 {
  private:
    vector<int> id;
    int count;
  public:
    UF1(int N) {
        count = N;
        id.resize(N, 0);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    ~UF1() {}
    
    int getCount() {
        return count;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int p) {
        return id[p];
    }

    void doUnion(int p, int q) {
        int pId = find(p);
        int qId = find(q);

        if (pId == qId) {
            return;
        }

        for (int i = 0; i < id.size(); i++) {
            if (id[i] == pId) {
                id[i] = qId;
            }
        }
        count--;
    }
};
//** 2. Quick-union, O(n) find, O(1) union
class UF2 {
  private:
    vector<int> id;
    int count;
  public:
    UF2(int N) {
        count = N;
        id.resize(N, 0);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    ~UF2() {}
    
    int getCount() {
        return count;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    void doUnion(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) {
            return;
        }

        id[pRoot] = qRoot;
        count--;
    }
};
//** 3. Weighted-quick-union, O(lgN) find, O(lgN) union
class UF3 {
  private:
    vector<int> id;
    vector<int> sz;
    int count;
  public:
    UF3(int N) {
        count = N;
        id.resize(N, 0);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
        sz.resize(N, 1);
    }

    ~UF3() {}
    
    int getCount() {
        return count;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    void doUnion(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) {
            return;
        }

        if (sz[pRoot] < sz[qRoot]) {
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            id[qRoot] = pRoot;
            sz[qRoot] += sz[pRoot];
        }
        count--;
    }
};
//** 4.Weighted-quick-union-with-path-compression, amoritized O(1)
class UF4 {
  private:
    vector<int> id;
    vector<int> sz;
    int count;
  public:
    UF4(int N) {
        count = N;
        id.resize(N, 0);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
        sz.resize(N, 1);
    }

    ~UF4() {}
    
    int getCount() {
        return count;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int find(int p) {
        int root = p;
        while (root != id[root]) {
            root = id[root];
        }
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }

    void doUnion(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) {
            return;
        }

        if (sz[pRoot] < sz[qRoot]) {
            id[pRoot] = qRoot;
            sz[qRoot] += sz[pRoot];
        } else {
            id[qRoot] = pRoot;
            sz[qRoot] += sz[pRoot];
        }
        count--;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // return func1(edges);
        return union_find(edges);
    }
    
    vector<int> union_find(vector<vector<int>>& edges) {
        vector<int> ret;
        int N = edges.size() + 1;
        // UF1 uf(N);
        // UF2 uf(N);
        // UF3 uf(N);
        UF4 uf(N);

        for (int i = 0; i < edges.size(); i++) {
            int p = edges[i][0];
            int q = edges[i][1];

            if (uf.connected(p, q)) {
                ret.emplace_back(p);
                ret.emplace_back(q);
                return ret;
            }

            uf.doUnion(p, q);
        }

        return ret;
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
