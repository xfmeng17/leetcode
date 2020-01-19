class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    // return func1(nums, target);
    return func2(nums, target);
  }

  vector<int> func1(vector<int> &nums, int target) {
    vector<int> result1(2, 0);
    vector<int> result2(2, 0);
    vector<int> result(2, -1);
    binarySearch(nums, target - 0.1, result1);
    binarySearch(nums, target + 0.1, result2);

    if (result1[0] != result2[0] || result1[1] != result2[1]) {
      result[0] = result1[0];
      result[1] = result2[1];
    }

    return result;
  }
  void binarySearch(vector<int> &nums, double target, vector<int> &result) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (double(nums[mid]) > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }

    result[0] = lo;
    result[1] = hi;

    // printf("res0=%d, res1=%d\n", result[0], result[1]);
  }

  vector<int> func2(vector<int> &nums, int target) {
    vector<int> ret(2, -1);
    ret[0] = leftBS(nums, target);
    ret[1] = rightBS(nums, target);
    // printf("ret0=%d, ret1=%d\n", ret[0], ret[1]);
    return ret;
  }
  int rightBS(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo < hi) {
      if (hi == lo + 1) {
        break;
      }
      int mid = (hi + lo) / 2;
      if (nums[mid] == target) {
        lo = mid;
      } else if (nums[mid] < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    if (hi >= 0 && nums[hi] == target) {
      return hi;
    }
    if (lo < nums.size() && nums[lo] == target) {
      return lo;
    }
    return -1;
  }
  int leftBS(vector<int> &nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo < hi) {
      if (hi == lo + 1) {
        break;
      }
      int mid = (hi + lo) / 2;
      if (nums[mid] == target) {
        hi = mid;
      } else if (nums[mid] < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }

    if (lo < nums.size() && nums[lo] == target) {
      return lo;
    }
    if (hi >= 0 && nums[hi] == target) {
      return hi;
    }
    return -1;
  }
};
