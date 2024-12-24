class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) { return func1(nums); }
  vector<vector<int>> func1(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret(1);
    int curr = 0, next = 0;
    while (curr < nums.size()) {
      vector<vector<int>> aux = mycopy(ret);
      aux = helper1(nums, &curr, &next, aux);
      for (int i = 0; i < aux.size(); i++) {
        ret.emplace_back(aux[i]);
      }
      curr = next;
    }
    return ret;
  }

  vector<vector<int>> mycopy(vector<vector<int>> &arr) {
    vector<vector<int>> aux;
    for (auto a : arr) {
      vector<int> row(a.begin(), a.end());
      aux.emplace_back(row);
    }
    return aux;
  }

  vector<vector<int>> helper1(vector<int> &nums, int *curr, int *next,
                              vector<vector<int>> &arr) {
    vector<vector<int>> ret;
    int lo = *curr, hi = *curr;
    while (hi < nums.size() && nums[hi] == nums[lo]) {
      hi++;
    }
    *next = hi;
    hi--;

    for (int mid = lo; mid <= hi; mid++) {
      for (auto a : arr) {
        vector<int> aux(a.begin(), a.end());
        for (int i = lo; i <= mid; i++) {
          aux.emplace_back(nums[i]);
        }
        ret.emplace_back(aux);
      }
    }

    return ret;
  }
};