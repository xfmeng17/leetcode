class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    // return func1(image, sr, sc, newColor);
    return func2(image, sr, sc, newColor);
  }

  // and yes I remember a lot the cord I written when worked at SenseTime
  // it's alway hurt to admit that you have just done some useless think
  vector<vector<int>> func1(vector<vector<int>> &image, int sr, int sc,
                            int newColor) {
    helper(image, sr, sc, -newColor, image[sr][sc]);
    for (int i = 0; i < image.size(); i++) {
      for (int j = 0; j < image[0].size(); j++) {
        if (image[i][j] < 0) {
          image[i][j] = -image[i][j];
        }
      }
    }
    return image;
  }
  void helper(vector<vector<int>> &image, int sr, int sc, int newColor,
              int oldColor) {
    if (image[sr][sc] != oldColor) {
      return;
    }
    image[sr][sc] = newColor;
    if (sr - 1 >= 0) {
      helper(image, sr - 1, sc, newColor, oldColor);
    }
    if (sr + 1 < image.size()) {
      helper(image, sr + 1, sc, newColor, oldColor);
    }
    if (sc - 1 >= 0) {
      helper(image, sr, sc - 1, newColor, oldColor);
    }
    if (sc + 1 < image[0].size()) {
      helper(image, sr, sc + 1, newColor, oldColor);
    }
    return;
  }

  // ref: trick is when newColor is same as oldColor
  // just done nothing
  vector<vector<int>> func2(vector<vector<int>> &image, int sr, int sc,
                            int newColor) {
    if (image[sr][sc] == newColor) {
      // do nothing
    } else {
      dfs(image, sr, sc, image[sr][sc], newColor);
    }
    return image;
  }
  void dfs(vector<vector<int>> &image, int sr, int sc, int oldColor,
           int newColor) {
    if (image[sr][sc] != oldColor) {
      return;
    }
    image[sr][sc] = newColor;
    if (sr - 1 >= 0) {
      dfs(image, sr - 1, sc, oldColor, newColor);
    }
    if (sr + 1 < image.size()) {
      dfs(image, sr + 1, sc, oldColor, newColor);
    }
    if (sc - 1 >= 0) {
      dfs(image, sr, sc - 1, oldColor, newColor);
    }
    if (sc + 1 < image[0].size()) {
      dfs(image, sr, sc + 1, oldColor, newColor);
    }
    return;
  }
};
