class Solution {
public:
  bool judgeCircle(string moves) {
    int horizontal = 0;
    int vertical = 0;
    for (char m : moves) {
      switch (m) {
      case 'L':
        horizontal++;
        break;
      case 'R':
        horizontal--;
        break;
      case 'U':
        vertical++;
        break;
      case 'D':
        vertical--;
        break;
      }
    }
    return horizontal == 0 && vertical == 0;
  }
};