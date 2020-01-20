class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    unordered_map<int, int> map;
    for (int n : nums1) {
      map[n]++;
    }
    for (int n : nums2) {
      if (map[n] > 0) {
        res.push_back(n);
        map[n]--;
      }
    }
    return res;
  }
};
