class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &nums) {
    vector<int> rank(nums);
    sort(rank.begin(), rank.end(), greater<int>());
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++) {
      // int x = 1 + bs(rank, 0, rank.size(), nums[i]);
      int x = 1 + bs(rank, nums[i]);
      if (x == 1) {
        ans.push_back("Gold Medal");
      } else if (x == 2) {
        ans.push_back("Silver Medal");
      } else if (x == 3) {
        ans.push_back("Bronze Medal");
      } else {
        ans.push_back(to_string(x));
      }
    }
    return ans;
  }

  /** recursion will cause Memory Limit Exceeded **/

  // int bs(vector<int> rank, int lo, int hi, int score) {
  // 	if (hi < lo) {
  // 		return -1;
  // 	}
  // 	int mid = lo + (hi - lo) / 2;
  // 	if (rank[mid] == score) {
  // 		return mid;
  // 	} else if (rank[mid] > score) {
  // 		return bs(rank, mid + 1, hi, score);
  // 	} else {
  // 		return bs(rank, lo, mid - 1, score);
  // 	}
  // }

  int bs(vector<int> rank, int score) {
    int lo = 0;
    int hi = rank.size();
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (rank[mid] == score) {
        return mid;
      } else if (rank[mid] > score) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return -1;
  }
};
