class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    // return func1(nums);
    // return func2(nums);
    return func3(nums);
  }

  /*
   * Time: O(n), standard stack
   * WA with case:
   * Input: [1,2,3,2,1]
   * Ouput: [2,3,-1,3,3]
   * Excep: [2,3,-1,3,2]
   */
  vector<int> func1(vector<int> &nums) {
    vector<int> res(nums.size(), -1);
    stack<int> stk;
    int greatest = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (stk.empty()) {
        stk.push(i);
        greatest = nums[i];
      } else {
        while (!stk.empty() && nums[i] > nums[stk.top()]) {
          res[stk.top()] = nums[i];
          stk.pop();
        }
        if (stk.empty()) {
          greatest = nums[i];
        }
        stk.push(i);
      }
    }
    while (!stk.empty() && greatest > nums[stk.top()]) {
      res[stk.top()] = greatest;
      stk.pop();
    }
    // while (!stk.empty()) {
    // 	res[stk.top()] = -1;
    // 	stk.pop();
    // }
    return res;
  }

  /*
   * Time: O(n), standard stack
   * WA with case:
   * Input: [5,4,3,2,1]
   * Ouput: [-1,5,4,3,2]
   * Excep: [-1,5,5,5,5]
   */
  vector<int> func2(vector<int> &nums) {
    vector<int> res(nums.size(), -1);
    stack<int> stk;
    for (int i = 0; i < nums.size(); i++) {
      if (stk.empty()) {
        stk.push(i);
      } else {
        while (!stk.empty() && nums[i] > nums[stk.top()]) {
          res[stk.top()] = nums[i];
          stk.pop();
        }
        stk.push(i);
      }
    }
    // ** reverse assign
    stack<int> tmp;
    while (!stk.empty()) {
      if (tmp.empty()) {
        tmp.push(stk.top());
        stk.pop();
      } else {
        while (!tmp.empty() && nums[stk.top()] > nums[tmp.top()]) {
          res[tmp.top()] = nums[stk.top()];
          tmp.pop();
        }
        tmp.push(stk.top());
        stk.pop();
      }
    }
    return res;
  }

  /*
   * Time: O(n), standard stack, twice iteration
   */
  vector<int> func3(vector<int> &nums) {
    vector<int> res(nums.size(), -1);
    stack<int> stk;
    for (int i = 0; i < nums.size(); i++) {
      if (stk.empty()) {
        stk.push(i);
      } else {
        while (!stk.empty() && nums[i] > nums[stk.top()]) {
          res[stk.top()] = nums[i];
          stk.pop();
        }
        stk.push(i);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      while (!stk.empty() && nums[i] > nums[stk.top()]) {
        res[stk.top()] = nums[i];
        stk.pop();
      }
    }
    // ** reverse assign
    stack<int> tmp;
    while (!stk.empty()) {
      if (tmp.empty()) {
        tmp.push(stk.top());
        stk.pop();
      } else {
        while (!tmp.empty() && nums[stk.top()] > nums[tmp.top()]) {
          res[tmp.top()] = nums[stk.top()];
          tmp.pop();
        }
        tmp.push(stk.top());
        stk.pop();
      }
    }
    return res;
  }
};