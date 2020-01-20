class Solution {
public:
  string reverseStr(string s, int k) {
    // return func1(s, k);
    // return func2(s, k);
    return func3(s, k);
  }

  //** AC but string += is really slow
  string func1(string s, int k) {
    int N = s.length();
    int lo = 0;
    string res = "";
    while (lo < N) {
      int mid = lo + k - 1;
      int hi = lo + 2 * k - 1;
      for (int i = min(mid, N - 1); i >= lo; i--) {
        res += s[i];
      }
      for (int i = mid + 1; i <= min(hi, N - 1); i++) {
        res += s[i];
      }
      lo += 2 * k;
    }
    return res;
  }

  //** more faster than func1(), but we can try in-place solution
  string func2(string s, int k) {
    int N = s.length();
    int lo = 0;
    vector<char> res(N, ' ');
    int idx = 0;
    while (lo < N) {
      int mid = lo + k - 1;
      int hi = lo + 2 * k - 1;
      for (int i = min(mid, N - 1); i >= lo; i--) {
        res[idx++] = s[i];
      }
      for (int i = mid + 1; i <= min(hi, N - 1); i++) {
        res[idx++] = s[i];
      }
      lo += 2 * k;
    }
    return string(res.begin(), res.end());
  }

  string func3(string s, int k) {
    int N = s.length();
    int lo = 0;
    while (lo < N) {
      int mid = lo + k - 1;
      int hi = lo + 2 * k - 1;
      for (int beg = lo, end = min(mid, N - 1); beg < end; beg++, end--) {
        char temp = s[beg];
        s[beg] = s[end];
        s[end] = temp;
      }
      lo += 2 * k;
    }
    return s;
  }
};
