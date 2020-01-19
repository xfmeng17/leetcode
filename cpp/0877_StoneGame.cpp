class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    // return func1(piles);
    return func2(piles);
  }
  // ** greedy algorithm
  // ** wrong case: 3 2 10 4
  bool func1(vector<int> &piles) {
    int alex = 0;
    int lee = 0;
    int i = 0, j = piles.size() - 1;
    while (i < j) {
      if (piles[i] > piles[j]) {
        alex += piles[i];
        i++;
      } else {
        alex += piles[j];
        j--;
      }
      if (piles[i] > piles[j]) {
        lee += piles[i];
        i++;
      } else {
        lee += piles[j];
        j--;
      }
    }
    return alex > lee;
  }

  // ** reference
  bool func2(vector<int> &piles) { return true; }
};
