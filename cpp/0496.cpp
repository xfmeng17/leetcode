class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
    // ** easy one, time f(n*n)
    // return func1(findNums, nums);
    // ** time f(n) and space f(n)
    return func2(findNums, nums);
  }

  vector<int> func1(vector<int> &findNums, vector<int> &nums) {
    vector<int> res(findNums.size());
    for (int i = 0; i < findNums.size(); i++) {
      res[i] = -1;
      int k = 0;
      while (nums[k] != findNums[i]) {
        k++;
      }
      for (int j = k + 1; j < nums.size(); j++) {
        if (nums[j] > findNums[i]) {
          res[i] = nums[j];
          break;
        }
      }
    }
    return res;
  }

  vector<int> func2(vector<int> &findNums, vector<int> &nums) {
    stack<int> stk;
    unordered_map<int, int> map;
    for (int n : nums) {
      while (stk.size() && stk.top() < n) {
        map[stk.top()] = n;
        stk.pop();
      }
      stk.push(n);
    }
    vector<int> res;
    for (int n : findNums) {
      res.push_back(map.count(n) ? map[n] : -1);
    }
    return res;
  }
};
