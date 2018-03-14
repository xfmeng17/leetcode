class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
    	return func1(nums);
    }

    // hash map
    int func1(vector<int>& nums) {
    	unordered_map<int, pair<int, int>> map;
    	int degree = 1;
    	int distance = 1;
    	for (int i = 0; i < nums.size(); i++) {
    		unordered_map<int, pair<int, int>>::iterator got;
    		if ((got = map.find(nums[i])) != map.end()) {
    			int d = ++(got->second.second);
    			if (d > degree) {
    				degree = d;
    				distance = i - got->second.first + 1;
    			} else if (d == degree) {
    				distance = std::min(distance, (i - got->second.first + 1));
    			} else {
    				// do nothing
    			}

    		} else {
    			map.insert(make_pair(nums[i], make_pair(i, 1)));
    		}
    	}
    	return distance;
    }
};
