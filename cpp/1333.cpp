class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>> &restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<vector<int>> aux;
    vector<int> ret;

    for (int i = 0; i < restaurants.size(); i++) {
      if (veganFriendly == 1 && restaurants[i][2] == 0) {
        continue;
      }
      if (restaurants[i][3] > maxPrice) {
        continue;
      }
      if (restaurants[i][4] > maxDistance) {
        continue;
      }
      aux.emplace_back(restaurants[i]);
    }

    sort(aux.begin(), aux.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[1] > b[1]) {
             return true;
           } else if (a[1] < b[1]) {
             return false;
           }
           return a[0] > b[0];
         });

    for (auto a : aux) {
      ret.emplace_back(a[0]);
    }
    return ret;
  }
};