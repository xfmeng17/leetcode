class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    // return func1(nums);
    return func2(nums);
  }
  vector<vector<int>> func1(vector<int> &nums) {
    vector<vector<int>> ret(1);
    for (int i = 0; i < nums.size(); i++) {
      vector<vector<int>> aux1;
      for (auto r : ret) {
        vector<int> aux2(r.begin(), r.end());
        aux2.emplace_back(nums[i]);
        aux1.emplace_back(aux2);
      }
      for (auto a : aux1) {
        ret.emplace_back(a);
      }
    }
    return ret;
  }
  vector<vector<int>> func2(vector<int> &nums) {
    vector<vector<int>> ret(1);
    for (int i = 0; i < nums.size(); i++) {
      vector<vector<int>> aux = mycopy(ret);
      for (int j = 0; j < aux.size(); j++) {
        aux[j].emplace_back(nums[i]);
      }
      for (int j = 0; j < aux.size(); j++) {
        ret.emplace_back(aux[j]);
      }
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
};