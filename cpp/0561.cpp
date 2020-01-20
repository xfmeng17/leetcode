class Solution {
public:
  int arrayPairSum(vector<int> &nums) { return func2(nums); }
  // ** simple sort
  int func1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      res += nums[i];
    }
    return res;
  }
  // ** O(n) hashtable
  int func2(vector<int> &nums) {
    vector<int> table(20001, 0);
    for (int n : nums) {
      table[n + 10000]++;
    }
    int res = 0;
    bool flag = true;
    int i = 0;
    while (i < 20001) {
      if (table[i] >= 1) {
        res = flag ? res + i - 10000 : res;
        flag ^= 1;
        table[i]--;
      }
      if (table[i] == 0) {
        i++;
      }
    }
    return res;
  }
};