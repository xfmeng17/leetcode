class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    // return func1(nums);
    // return func2(nums);
    // return func3(nums);
    // return func4(nums);
    // return func5(nums);
    return func6(nums);
  }

  // ** top-down recursive, TLE
  int func1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> singleNums;
    vector<int> singleSize;
    for (auto n : nums) {
      if (singleNums.size() > 0 && singleNums.back() == n) {
        singleSize.back()++;
      } else {
        singleNums.push_back(n);
        singleSize.push_back(1);
      }
    }
    return helper1(singleNums, singleSize, 0, singleNums.size() - 1);
  }
  int helper1(vector<int> &singleNums, vector<int> &singleSize, int lo,
              int hi) {
    if (lo < 0 || hi >= singleNums.size() || lo > hi) {
      return 0;
    }
    int ret = 0;
    for (int i = lo; i <= hi; i++) {
      int lf = 0;
      if (i - 1 >= 0) {
        if (singleNums[i - 1] == singleNums[i] - 1) {
          lf = helper1(singleNums, singleSize, lo, i - 2);
        } else {
          lf = helper1(singleNums, singleSize, lo, i - 1);
        }
      }
      int rt = 0;
      if (i + 1 <= hi) {
        if (singleNums[i + 1] == singleNums[i] + 1) {
          rt = helper1(singleNums, singleSize, i + 2, hi);
        } else {
          rt = helper1(singleNums, singleSize, i + 1, hi);
        }
      }
      int cur = lf + rt + singleNums[i] * singleSize[i];
      ret = max(ret, cur);
    }

    return ret;
  }

  // ** recursive + memoization, still TLE
  int func2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> singleNums;
    vector<int> singleSize;
    for (auto n : nums) {
      if (singleNums.size() > 0 && singleNums.back() == n) {
        singleSize.back()++;
      } else {
        singleNums.push_back(n);
        singleSize.push_back(1);
      }
    }

    int n = singleNums.size();
    vector<vector<int>> memo(n, vector<int>(n, 0));

    return helper2(singleNums, singleSize, 0, n - 1, memo);
  }
  int helper2(vector<int> &singleNums, vector<int> &singleSize, int lo, int hi,
              vector<vector<int>> &memo) {

    if (lo < 0 || hi >= singleNums.size() || lo > hi) {
      return 0;
    }
    if (memo[lo][hi] > 0) {
      return memo[lo][hi];
    }

    for (int i = lo; i <= hi; i++) {
      int lf = 0;
      if (i - 1 >= 0) {
        if (singleNums[i - 1] == singleNums[i] - 1) {
          lf = helper2(singleNums, singleSize, lo, i - 2, memo);
        } else {
          lf = helper2(singleNums, singleSize, lo, i - 1, memo);
        }
      }
      int rt = 0;
      if (i + 1 <= hi) {
        if (singleNums[i + 1] == singleNums[i] + 1) {
          rt = helper2(singleNums, singleSize, i + 2, hi, memo);
        } else {
          rt = helper2(singleNums, singleSize, i + 1, hi, memo);
        }
      }
      memo[lo][hi] = max(memo[lo][hi], lf + rt + singleNums[i] * singleSize[i]);
    }

    return memo[lo][hi];
  }

  // ** dp from discuss
  int func3(vector<int> &nums) {
    vector<int> cnt(100001, 0);
    for (auto n : nums)
      cnt[n] += n;

    vector<int> dp(100003, 0);
    for (int i = 10000; i >= 0; i--) {
      dp[i] = max(cnt[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
  }
  // ** dp, trim to 2 pointer
  int func4(vector<int> &nums) {
    vector<int> cnt(100001, 0);
    for (auto n : nums)
      cnt[n] += n;

    int p0 = 0, p1 = 0, p2 = 0;
    for (int i = 10000; i >= 0; i--) {
      p0 = max(cnt[i] + p2, p1);
      p2 = p1;
      p1 = p0;
    }
    return p0;
  }

  // ** reduce to the House Robbers question
  // ** just get TLE
  int func5(vector<int> &nums) {
    vector<int> cnt(10001, 0);
    for (auto n : nums)
      cnt[n] += n;

    return helper5(cnt, cnt.size() - 1);
  }
  int helper5(vector<int> &nums, int i) {
    if (i < 0) {
      return 0;
    }
    return max(helper5(nums, i - 2) + nums[i], helper5(nums, i - 1));
  }

  // ** myself dp
  // ** not correct in formula
  // ** test input: [8,7,3,8,1,4,10,10,10,2]
  int func6(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> singleNums;
    vector<int> singleSize;
    for (auto n : nums) {
      if (singleNums.size() > 0 && singleNums.back() == n) {
        singleSize.back()++;
      } else {
        singleNums.push_back(n);
        singleSize.push_back(1);
      }
    }
    for (int i = 0; i < singleNums.size(); i++) {
      cout << singleNums[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < singleSize.size(); i++) {
      cout << singleSize[i] << ", ";
    }
    cout << endl;

    int n = singleNums.size();

    int p0 = 0, p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
      cout << singleNums[i] << " ";
      int pick = singleNums[i] * singleSize[i] + p2;
      cout << "pick=" << pick;
      bool flag = false;
      if (i - 1 >= 0 && singleNums[i] - 1 != singleNums[i - 1]) {
        flag = true;
        if (i - 2 >= 0 && singleNums[i - 1] - 1 == singleNums[i - 2]) {
          flag = false;
        }
      }
      if (flag)
        pick += singleNums[i - 1] * singleSize[i - 1];
      cout << ", pick=" << pick;

      int notp = p1;
      cout << ", notp=" << notp;
      p0 = max(pick, notp);
      cout << ", p1=" << p1;
      cout << ", p2=" << p2;

      p2 = p1;
      p1 = p0;
      cout << ", p1=" << p1;
      cout << ", p2=" << p2 << endl;
    }

    return p0;
  }
};
