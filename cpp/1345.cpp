class Solution {
public:
  int minJumps(vector<int> &arr) { return func1(arr); }

  int func1(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> index(n);
    vector<int> memo(n, n + 1);
    vector<bool> marked(n, false);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (arr[i] == arr[j]) {
          index[i].emplace_back(j);
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //     for (auto x : index[i]) {
    //         printf("%d ", x);
    //     }
    //     printf("\n");
    // }
    int ret = helper1(arr, 0, index, memo, marked);
    for (int i = 0; i < memo.size(); i++) {
      printf("i=%d, memo=%d\n", i, memo[i]);
    }
    return ret;
  }

  int helper1(vector<int> &arr, int i, vector<vector<int>> &index,
              vector<int> &memo, vector<bool> &marked) {

    int n = arr.size();

    if (i < 0 || i >= n) {
      return n;
    }
    if (i == n - 1) {
      return 0;
    }
    if (arr[i] == arr[n - 1]) {
      return 1;
    }
    if (memo[i] < n) {
      return memo[i];
    }

    int ret = n;
    marked[i] = true;

    if (i - 1 >= 0 && arr[i - 1] != arr[i] && !marked[i - 1]) {
      ret = min(ret, 1 + helper1(arr, i - 1, index, memo, marked));
    }
    if (i + 1 < n && arr[i + 1] != arr[i] && !marked[i + 1]) {
      ret = min(ret, 1 + helper1(arr, i + 1, index, memo, marked));
    }
    for (auto idx : index[i]) {
      if (!marked[idx]) {
        ret = min(ret, 1 + helper1(arr, idx, index, memo, marked));
      }
    }

    memo[i] = ret;
    marked[i] = false;

    return ret;
  }
};

// [68,-94,-44,-18,-1,18,-87,29,-6,-87,-27,37,-57,7,18,68,-59,29,7,53,-27,-59,18,-1,18,-18,-59,-1,-18,-84,-20,7,7,-87,-18,-84,-20,-27]
// Excepted 5, I got 6