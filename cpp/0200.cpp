class UnionFind {
private:
    vector<int> id;
    vector<int> sz;
    int count;
public:
    UnionFind(int N) {
        count = N;
        id.resize(N, 0);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
        sz.resize(N, 1);
    }
    
    ~UnionFind() {}

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
        int p_root = find(p);
        int q_root = find(q);
        if (p_root == q_root) {
            return;
        }

        if (sz[p_root] < sz[q_root]) {
            id[p_root] = q_root;
            sz[q_root] += sz[p_root];
        } else {
            id[q_root] = p_root;
            sz[p_root] += sz[q_root];
        }
        count--;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {        
        // return func1(grid);
        return func2(grid);
    }
    int func1(vector<vector<char>>& grid) {
        int M = grid.size();
        if (M <= 0) {
            return 0;
        }
        int N = grid[0].size();
        UnionFind uf(M*N);

        int count0 = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '0') {
                    count0++;
                    continue;
                }
                if (i-1 >= 0 && grid[i-1][j] == '1') {
                    uf.doUnion(i*N+j, (i-1)*N+j);
                }
                if (i+1 < M && grid[i+1][j] == '1') {
                    uf.doUnion(i*N+j, (i+1)*N+j);
                }
                if (j-1 >= 0 && grid[i][j-1] == '1') {
                    uf.doUnion(i*N+j, i*N+j-1);
                }
                if (j+1 < N && grid[i][j+1] == '1') {
                    uf.doUnion(i*N+j, i*N+j+1);
                }
            }
        }
        return uf.getCount() - count0;
    }
    int func2(vector<vector<char>>& grid) {
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                ret += helper2(grid, i, j);
            }
        }
        return ret;
    }
    int helper2(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() ||
            j < 0 || j >= grid[i].size() ||
            grid[i][j] == '0') {
        
            return 0;
        }

        grid[i][j] = '0';
        helper2(grid, i-1, j);
        helper2(grid, i+1, j);
        helper2(grid, i, j-1);
        helper2(grid, i, j+1);
        
        return 1;
    }
};

