class Solution {
public:
  vector<int> countBits(int num) {
    // return func1(num);
    return func2(num);
  }

  // ** easy one, O(n * sizeof(integer))
  vector<int> func1(int num) {
    vector<int> res;

    for (int i = 0; i <= num; i++) {
      unsigned cur = i;
      int cnt = 0;
      while (cur > 0) {
        cnt += cur & 1;
        cur = cur >> 1;
      }
      res.push_back(cnt);
    }

    return res;
  }
  vector<int> func2(int num) {
    vector<int> res;
    if (num < 0) {
      return res;
    }

    res.resize(num + 1);
    res.push_back(0);
    int e = 1;
    for (int i = 1; i <= num; i++) {
      if (i == e) {
        res.push_back(1);
        e *= 2;
      } else {
        res.push_back(res[e / 2] + res[i % (e / 2)]);
      }
    }

    return res;
  }
};