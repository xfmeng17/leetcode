class Solution {
public:
  int repeatedNTimes(vector<int> &A) {
    vector<bool> set(10001, false);
    for (auto n : A) {
      if (set[n])
        return n;
      else
        set[n] = true;
    }

    return -1;
  }
};
