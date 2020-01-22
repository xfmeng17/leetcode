# Union Find 并查集

## 2019-01 解决leetcode 684
结合解题代码和《算法4》1.5，总结一下

### 1. 并查集目的
解决 `动态连通性(Dynamic connectivity)` 的问题

### 2. 应用场景

- Network，网络，2点间建立通信
- Variable-name equivalence，变量名等价性，编译时，判定代码中，2个给定的变量名是否等价
- Mathematical sets，数学集合，判定给定输入p，q是否属于同一个集合

### 3. 名词概念

1. Equivalence，等价关系，若p和q是连接的，假设连接是一种等价关系，则
    - Reflexive，自反性，p和p是连接的
    - Symmetric，对称性，q和p是连接的
    - Transitive，传递性，q和r也是连接的，则p和r也是

### 4. 算法实现
代码地址：<https://github.com/xfmeng17/leetcode/blob/master/cpp/684_RedundantConnection.cpp>

1. 基本思想，union时，for便利
2. union是树型存储，根是一个树的ID
3. 2的基础上，加入weight。合并时，小树合入大树，find和union一般情况会降到O(lgn)
4. 3的基础上，加入路径压缩(path compression)，在find时，再套一层while循环将ID都指向根，摊还是O(1)，leetcode上可能因为测试样例不足，想过不如3明显

```cpp
// ** 1. Quick-find, O(1) find, 0(n) union
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
// ** 2. Quick-union, O(n) find, O(1) union
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
// ** 3. Weighted-quick-union, O(lgN) find, O(lgN) union
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
// ** 4.Weighted-quick-union-with-path-compression, amoritized O(1)
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
};
```