class Solution {
public:
  bool isOneBitCharacter(vector<int> &bits) {
    int x = 0;
    int size = bits.size();
    while (x < size) {
      if (bits[x] == 0) {
        x += 1;
      } else {
        x += 2;
        if (x == size) {
          return false;
        }
      }
    }
    return true;
  }
};
