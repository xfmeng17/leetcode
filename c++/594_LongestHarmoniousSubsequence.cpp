class Solution {
public:
    int findLHS(vector<int>& nums) {
    	return func1(nums);
    	// return func2(nums);
    }

    int func1(vector<int>& nums) {
		int res = 0;
		unordered_map<int, int> hashMap;

		for (auto n : nums) {
			hashMap[n]++;
		}
		for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
			int key = it->first;
			int lfVal = 0;
			if (hashMap.find(key - 1) != hashMap.end()) {
				lfVal = hashMap[key - 1];
			}
			int rtVal = 0;
			if (hashMap.find(key + 1) != hashMap.end()) {
				rtVal = hashMap[key + 1];
			}
			int sum = 0;
			if (lfVal > 0 || rtVal > 0) {
				sum = hashMap[key] + max(lfVal, rtVal);
			}
			if (sum > res) {
				res = sum;
			}
		}

		return res;
    }

    // ** Wrong, cause unordered_map is not thread-safety,
    // ** insert and iteration at same will case undefined behaviour.
    int func2(vector<int>& nums) {
    	int res = 0;
		unordered_map<int, int> hashMap;

		for (auto n : nums) {
			hashMap[n]++;
		}
		for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            printf("key = %d, val = %d\n", it->first, it->second);
			int key = it->first;
            // int val = 0;
			int val = max(hashMap[key - 1], hashMap[key + 1]);
			if (val > 0) {
				res = max(res, (it->second + val));
			}
            printf("k=%d, kv-1=%d, kv+1=%d\n", it->first, hashMap[key-1], hashMap[key+1]);
		}

		return res;
	}
};
