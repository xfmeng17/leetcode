class Solution {
public:
  vector<int> constructRectangle(int area) { return func1(area); }

  // worst case O(sqrt(n))
  vector<int> func1(int area) {
    vector<int> ans;
    int q = sqrt(area);
    for (int i = q; i > 0; i--) {
      if (area % i == 0) {
        ans.push_back(area / i);
        ans.push_back(i);
        break;
      }
    }
    return ans;
  }
};
