class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    sort(nums.begin(), nums.begin() + 3);
    int p1 = nums[2], p2 = nums[1], p3 = nums[0];
    int n1 = nums[0], n2 = nums[1];
    for (int i = 3; i < nums.size(); i++) {
      if (nums[i] > p1) {
        p3 = p2;
        p2 = p1;
        p1 = nums[i];
      } else if (nums[i] > p2) {
        p3 = p2;
        p2 = nums[i];
      } else if (nums[i] > p3) {
        p3 = nums[i];
      }
      if (nums[i] < n1) {
        n2 = n1;
        n1 = nums[i];
      } else if (nums[i] < n2) {
        n2 = nums[i];
      }
    }
    return max((p1 * p2 * p3), (p1 * n1 * n2));
  }
};
