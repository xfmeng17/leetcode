class Solution {
public:
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    // return func1(m, n, ops); // memory limit exceeded
    // return func2(m, n, ops);
    // return func3(m, n, ops);
    return func4(m, n, ops);
  }

  // bruce force
  // Time: O(k*m*n), k is the size of options
  // Space: O(m*n)
  int func1(int m, int n, vector<vector<int>> &ops) {
    int **matrix = new int *[m];
    for (int i = 0; i < m; i++) {
      matrix[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
    for (int k = 0; k < ops.size(); k++) {
      for (int i = 0; i < ops[k][0]; i++) {
        for (int j = 0; j < ops[k][1]; j++) {
          matrix[i][j]++;
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == matrix[0][0]) {
          sum++;
        }
      }
    }
    return sum;
  }

  // just save two angle
  // Time: O(k*(m+n)), k is the size of options
  // Space: O(m+n)
  int func2(int m, int n, vector<vector<int>> &ops) {
    int *row = new int[m];
    int *col = new int[n];
    for (int i = 0; i < m; i++) {
      row[i] = 0;
    }
    for (int j = 0; j < n; j++) {
      col[j] = 0;
    }
    for (int k = 0; k < ops.size(); k++) {
      for (int i = 0; i < ops[k][0]; i++) {
        row[i]++;
      }
      for (int j = 0; j < ops[k][1]; j++) {
        col[j]++;
      }
    }
    int r = 0, c = 0;
    for (int i = 0; i < m; i++) {
      if (row[i] == row[0]) {
        r++;
      }
    }
    for (int j = 0; j < n; j++) {
      if (col[j] == col[0]) {
        c++;
      }
    }
    delete[] row;
    delete[] col;
    return r * c;
  }

  // inspire from func2, just store the min number in ops
  // Time: O(k)
  // Space: O(1)
  int func3(int m, int n, vector<vector<int>> &ops) {
    int rowMin = m;
    int colMin = n;
    for (int k = 0; k < ops.size(); k++) {
      if (ops[k][0] < rowMin) {
        rowMin = ops[k][0];
      }
      if (ops[k][1] < colMin) {
        colMin = ops[k][1];
      }
    }
    return rowMin * colMin;
  }

  // ref: same to func3 but more short
  int func4(int m, int n, vector<vector<int>> &ops) {
    for (auto op : ops) {
      m = min(op[0], m);
      n = min(op[1], n);
    }
    return m * n;
  }
};
