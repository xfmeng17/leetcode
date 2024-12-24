class Solution {
public:
  int maxValueAfterReverse(vector<int> &nums) {
    // return func1(nums);
    return func2(nums);
  }

  int func1(vector<int> &nums) {
    int N = nums.size();
    int value = 0;
    int maxdiff = 0;
    for (int i = 0; i < N - 1; i++) {
      value += abs(nums[i] - nums[i + 1]);
    }
    // printf("value=%d\n", value);
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        int lo_old = nums[i];
        int lo_new = nums[j];
        int hi_old = nums[j];
        int hi_new = nums[i];

        int diff = 0;
        if (i > 0) {
          diff += abs(nums[i - 1] - lo_new) - abs(nums[i - 1] - lo_old);
        }
        if (j < N - 1) {
          diff += abs(hi_new - nums[j + 1]) - abs(hi_old - nums[j + 1]);
        }
        maxdiff = max(maxdiff, diff);
      }
    }

    return value + maxdiff;
  }

  /*
   * 2020-02-06, O(n) time solution:
   * The maximum result can be obtained by reversing some subarray [L, R],
   * and list the formula, and find out that we can calculate f(L) and f(R)
   * separately.
   *
   * Ignore edge cases(L=0 make L-1=-1 invalid etc), for [L, R]:
   * Result = S - abs(a[L] - a[L-1]) - abs(a[R] - a[R+1])
   *            + abs(a[L-1] - a[R]) + abs(a[L] - a[R+1])
   * In all 4 cases, a[L-1] <=> a[R] and a[L] <=> a[R+1], we can separate L
   * and R like this:
   * Case 1, a[L-1] <= a[R] and a[L] <= a[R+1]:
   *
   * S - abs(a[L] - a[L-1]) - abs(a[R] - a[R+1])
   *   + (a[R] - a[L-1]) + (a[R+1] - a[l])
   * ===>
   * S - abs(a[L] - a[L-1]) -  a[L-1] - a[L]
   *   - abs(a[R] - a[R+1]) +  a[R] + a[R+1]
   * ===>
   * S + X + Y
   *
   * that is, we get X = 0 - abs(a[L] - a[L-1]) - a[L-1] - a[L]
   *                 Y = 0 - abs(a[R] - a[R+1]) + a[R] + a[R+1]
   *
   * In X all about L-1 and L, in Y all about R and R+1, then we can calculate
   * X and Y in 2 O(n) iterations.
   *
   * Same Case 2, 3 and 4, just different X and Y and so, need 8 iterations
   * totally.
   */
  int func2(vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }
    if (nums.size() <= 2) {
      return abs(nums[0] - nums[1]);
    }

    int pre = prefix(nums);
    int mid = middle(nums);
    int suf = suffix(nums);
    // printf("pre=%d, mid=%d, suf=%d\n", pre, mid, suf);

    return max(pre, max(mid, suf));
  }
  int middle(vector<int> &nums) {
    int S = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      S += abs(nums[i] - nums[i + 1]);
    }

    int X1 = INT_MIN;
    int Y1 = INT_MIN;
    int X2 = INT_MIN;
    int Y2 = INT_MIN;
    int X3 = INT_MIN;
    int Y3 = INT_MIN;
    int X4 = INT_MIN;
    int Y4 = INT_MIN;
    /*
     * -abs(a[L-1] - a[L]) - abs(a[R] - a[R+1])
     * +abs(a[L-1] - a[R]) + abs(a[L] - a[R+1])
     * a[L-1] < a[R] and a[L] < a[R+1]
     * a[L-1] > a[R] and a[L] < a[R+1]
     * a[L-1] < a[R] and a[L] > a[R+1]
     * a[L-1] > a[R] and a[L] > a[R+1]
     */

    for (int L = 1; L < nums.size() - 1; L++) {
      X1 = max(X1, 0 - abs(nums[L] - nums[L - 1]) - nums[L - 1] - nums[L]);
      X2 = max(X2, 0 - abs(nums[L] - nums[L - 1]) + nums[L - 1] - nums[L]);
      X3 = max(X3, 0 - abs(nums[L] - nums[L - 1]) - nums[L - 1] + nums[L]);
      X4 = max(X4, 0 - abs(nums[L] - nums[L - 1]) + nums[L - 1] + nums[L]);
    }
    for (int R = 1; R < nums.size() - 1; R++) {
      Y1 = max(Y1, 0 - abs(nums[R] - nums[R + 1]) + nums[R] + nums[R + 1]);
      Y2 = max(Y2, 0 - abs(nums[R] - nums[R + 1]) - nums[R] + nums[R + 1]);
      Y3 = max(Y3, 0 - abs(nums[R] - nums[R + 1]) + nums[R] - nums[R + 1]);
      Y4 = max(Y4, 0 - abs(nums[R] - nums[R + 1]) - nums[R] - nums[R + 1]);
    }

    int ret = S;
    ret = max(ret, S + X1 + Y1);
    ret = max(ret, S + X2 + Y2);
    ret = max(ret, S + X3 + Y3);
    ret = max(ret, S + X4 + Y4);

    return ret;
  }
  int prefix(vector<int> &nums) {
    int S = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      S += abs(nums[i] - nums[i + 1]);
    }
    int ret = S;
    // -abs(a[L-1] - a[L]) - abs(a[R] - a[R+1])
    // +abs(a[L-1] - a[R]) + abs(a[L] - a[R+1])
    int L = 0;
    for (int R = 0; R < nums.size() - 1; R++) {
      ret =
          max(ret, S - abs(nums[R] - nums[R + 1]) + abs(nums[L] - nums[R + 1]));
    }
    return ret;
  }
  int suffix(vector<int> &nums) {
    int S = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      S += abs(nums[i] - nums[i + 1]);
    }
    int ret = S;
    // -abs(a[L-1] - a[L]) - abs(a[R] - a[R+1])
    // +abs(a[L-1] - a[R]) + abs(a[L] - a[R+1])
    int R = nums.size() - 1;
    for (int L = 1; L < nums.size(); L++) {
      ret =
          max(ret, S - abs(nums[L - 1] - nums[L]) + abs(nums[L - 1] - nums[R]));
    }
    return ret;
  }
};