class Solution {
public:
  int maxStudents(vector<vector<char>> &seats) {
    int m = seats.size();
    int n = seats[0].size();

    int sum0 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j += 3) {
        if (seats[i][j] == '.') {
          sum0 += 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (j % 3 == 0) {
          continue;
        }
        if (seats[i][j] == '#') {
          continue;
        }
        // left
        if (i - 1 >= 0 && seats[i - 1][j] == '.') {
          continue;
        }
        // right
        if (i + 1 < m && seats[i + 1][j] == '.') {
          continue;
        }
        // left-up
        if (i - 1 >= 0 && j - 1 >= 0 && seats[i - 1][j - 1] == '.') {
          continue;
        }
        // right-up
        if (i + 1 < m && j - 1 >= 0 && seats[i + 1][j - 1] == '.') {
          continue;
        }
        // left-down
        if (i - 1 >= 0 && j + 1 < n && seats[i - 1][j + 1] == '.') {
          continue;
        }
        // right-down
        if (i + 1 < m && j + 1 < n && seats[i + 1][j + 1] == '.') {
          continue;
        }
        sum0 += 1;
      }
    }

    int sum1 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j += 3) {
        if (seats[i][j] == '.') {
          sum1 += 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (j % 3 == 1) {
          continue;
        }
        if (seats[i][j] == '#') {
          continue;
        }
        // left
        if (i - 1 >= 0 && seats[i - 1][j] == '.') {
          continue;
        }
        // right
        if (i + 1 < m && seats[i + 1][j] == '.') {
          continue;
        }
        // left-up
        if (i - 1 >= 0 && j - 1 >= 0 && seats[i - 1][j - 1] == '.') {
          continue;
        }
        // right-up
        if (i + 1 < m && j - 1 >= 0 && seats[i + 1][j - 1] == '.') {
          continue;
        }
        // left-down
        if (i - 1 >= 0 && j + 1 < n && seats[i - 1][j + 1] == '.') {
          continue;
        }
        // right-down
        if (i + 1 < m && j + 1 < n && seats[i + 1][j + 1] == '.') {
          continue;
        }
        sum1 += 1;
      }
    }

    int sum2 = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 2; j < n; j += 3) {
        if (seats[i][j] == '.') {
          sum2 += 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (j % 3 == 2) {
          continue;
        }
        if (seats[i][j] == '#') {
          continue;
        }
        // left
        if (i - 1 >= 0 && seats[i - 1][j] == '.') {
          continue;
        }
        // right
        if (i + 1 < m && seats[i + 1][j] == '.') {
          continue;
        }
        // left-up
        if (i - 1 >= 0 && j - 1 >= 0 && seats[i - 1][j - 1] == '.') {
          continue;
        }
        // right-up
        if (i + 1 < m && j - 1 >= 0 && seats[i + 1][j - 1] == '.') {
          continue;
        }
        // left-down
        if (i - 1 >= 0 && j + 1 < n && seats[i - 1][j + 1] == '.') {
          continue;
        }
        // right-down
        if (i + 1 < m && j + 1 < n && seats[i + 1][j + 1] == '.') {
          continue;
        }
        sum1 += 1;
      }
    }

    return max(sum2, max(sum1, sum0));
  }
};