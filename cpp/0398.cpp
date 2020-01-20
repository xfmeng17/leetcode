/**
 * 1. Basic queue solution, store every element, O(n) space but O(1) pick
 */
// class Solution {
// public:
// 	unordered_map<int, queue<int>> map;
// public:
//     Solution(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//         	map[nums[i]].emplace(i);
//         }
//     }

//     int pick(int target) {
//         if (map.find(target) == map.end()) {
//         	return -1;
//         }
//         queue<int>& index = map[target];
//         index.emplace(index.front());
//         index.pop();

//         return index.front();
//     }
// };

/**
 * 2. Random choose, O(1) space but O(n) pick
 */
// class Solution {
// public:
//     vector<int> arr;
// public:
//     Solution(vector<int>& nums) {
//         arr = nums;
//         srand(time(NULL));
//     }

//     int pick(int target) {
//         vector<int> candidate;
//         for (int i = 0; i < arr.size(); i++) {
//             if (arr[i] == target) {
//                 candidate.emplace_back(i);
//             }
//         }
//         return candidate[rand() % candidate.size()];
//     }
// };

/**
 * 3. Random choose, "start = i + 1" is the trick, if not will not be equal
 * random
 */
class Solution {
public:
  vector<int> arr;
  int start = 0;

public:
  Solution(vector<int> &nums) { arr = nums; }

  int pick(int target) {
    for (int i = start; i < arr.size(); i++) {
      if (arr[i] == target) {
        start = i + 1;
        return i;
      }
    }
    for (int i = 0; i < start; i++) {
      if (arr[i] == target) {
        start = i + 1;
        return i;
      }
    }
    return -1;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */