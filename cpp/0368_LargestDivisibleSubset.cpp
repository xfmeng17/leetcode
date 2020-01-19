class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    // return func1(nums);
    // return func2(nums);
    // return func3(nums);
    // return func4(nums);
    return func5(nums);
  }

  // ** naive try, iterate
  // ** O(n^3)
  vector<int> func1(vector<int> &nums) {
    int N = nums.size();
    if (N <= 1) {
      return vector<int>(nums);
    }
    sort(nums.begin(), nums.end());

    vector<int> res;
    for (int i = 0; i < N; i++) {

      vector<int> aux;
      aux.push_back(nums[i]);

      for (int j = 0; j < N; j++) {
        if (j == i) {
          continue;
        }
        bool pick = true;
        for (auto x : aux) {
          if ((x % nums[j] != 0) && (nums[j] % x != 0)) {
            pick = false;
            break;
          }
        }
        if (pick) {
          aux.push_back(nums[j]);
        }
      }

      if (aux.size() > res.size()) {
        res = aux;
      }
    }

    return res;
  }

  // ** sort + two pointer
  // ** O(n^2)
  vector<int> func2(vector<int> &nums) {
    int N = nums.size();
    if (N <= 1) {
      return vector<int>(nums);
    }

    sort(nums.begin(), nums.end());
    vector<int> res;
    for (int i = 0; i < N; i++) {

      vector<int> aux;
      aux.push_back(nums[i]);
      int lf = nums[i];
      int rt = nums[i];
      for (int j = i - 1; j >= 0; j--) {
        if (lf % nums[j] == 0) {
          aux.push_back(nums[j]);
          lf = nums[j];
        }
      }
      for (int j = i + 1; j < N; j++) {
        if (nums[j] % rt == 0) {
          aux.push_back(nums[j]);
          rt = nums[j];
        }
      }
      if (aux.size() > res.size()) {
        res = aux;
      }
    }

    return res;
  }

  // ** same with func2 but reduce space using
  vector<int> func3(vector<int> &nums) {
    int N = nums.size();
    if (N <= 1) {
      return vector<int>(nums);
    }
    sort(nums.begin(), nums.end());
    int idx = 0;
    int len = 0;

    for (int i = 0; i < N; i++) {
      int len = 1;
      int lf = nums[i];
      for (int j = i - 1; j >= 0; j--) {
        if (lf % nums[j] == 0) {
          lf = nums[j];
          len++;
        }
      }
      int rt = nums[i];
      for (int j = i + 1; j < N; j++) {
        if (nums[j] % rt == 0) {
          rt = nums[j];
          len++;
        }
      }
      if (len > len) {
        idx = i;
        len = len;
      }
    }

    vector<int> res;
    res.push_back(nums[idx]);
    int lf = nums[idx];
    for (int j = idx - 1; j >= 0; j--) {
      if (lf % nums[j] == 0) {
        res.push_back(nums[j]);
        lf = nums[j];
      }
    }
    int rt = nums[idx];
    for (int j = idx + 1; j < N; j++) {
      if (nums[j] % rt == 0) {
        res.push_back(nums[j]);
        rt = nums[j];
      }
    }

    return res;
  }

  // ** sort with dp:
  // ** lf[i] record nums[0, i] divisible number
  // ** rt[i] record nums[i, N-1] divisible number
  vector<int> func4(vector<int> &nums) {
    int N = nums.size();
    if (N <= 1) {
      return vector<int>(nums);
    }
    sort(nums.begin(), nums.end());
    vector<int> dpLeft(N, 1);
    vector<int> dpRight(N, 1);

    for (int i = 0; i < N; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] == 0) {
          dpLeft[i] = max(dpLeft[i], 1 + dpLeft[j]);
        }
      }
    }
    for (int i = N - 1; i >= 0; i--) {
      for (int j = i + 1; j < N; j++) {
        if (nums[j] % nums[i] == 0) {
          dpRight[i] = max(dpRight[i], 1 + dpRight[j]);
        }
      }
    }

    for (int i = 0; i < N; i++) {
      cout << dpLeft[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
      cout << dpRight[i] << " ";
    }
    cout << endl;
    int idx = 0;
    int len = 0;
    for (int i = 0; i < N; i++) {
      if (dpLeft[i] + dpRight[i] - 1 > len) {
        len = dpLeft[i] + dpRight[i] - 1;
        idx = i;
      }
    }

    vector<int> res;
    res.push_back(nums[idx]);
    int lf = nums[idx];
    for (int i = idx - 1; i >= 0; i--) {
      int l = dpLeft[i] + dpRight[i] - 1;
      if (lf % nums[i] == 0 && l == len) {
        res.push_back(nums[i]);
        lf = nums[i];
      }
    }
    int rt = nums[idx];
    for (int i = idx + 1; i < N; i++) {
      int l = dpLeft[i] + dpRight[i] - 1;
      if (nums[i] % rt == 0 && l == len) {
        res.push_back(nums[i]);
        rt = nums[i];
      }
    }

    return res;
  }

  // ** reference
  // ** two 1D array, len[i] record length,
  // ** pre[i] record last index
  vector<int> func5(vector<int> &nums) {
    int N = nums.size();
    if (N <= 1) {
      return vector<int>(nums);
    }
    sort(nums.begin(), nums.end());

    vector<int> len(N, 1);
    vector<int> pre(N, -1);

    int maxLen = 0, maxIdx = -1;
    for (int i = 0; i < N; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] == 0) {
          if (1 + len[j] > len[i]) {
            len[i] = 1 + len[j];
            pre[i] = j;
          }
        }
      }
      if (len[i] > maxLen) {
        maxLen = len[i];
        maxIdx = i;
      }
    }

    vector<int> res;
    while (maxIdx >= 0) {
      res.push_back(nums[maxIdx]);
      maxIdx = pre[maxIdx];
    }

    return res;
  }
};
