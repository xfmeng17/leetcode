class Solution {
public:
  int minSetSize(vector<int> &arr) {
    vector<int> set(100001, 0);
    for (auto a : arr) {
      set[a]++;
    }

    sort(set.begin(), set.end(), [](auto a, auto b) { return a > b; });

    int target = arr.size() / 2;
    int i = 0;
    while (target > 0) {
      target -= set[i++];
    }

    return i;
  }
};
