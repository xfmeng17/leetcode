class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		// return func1(points); // Time Limit Exceeded
		return func2(points);
	}

	// brute force 
	// Time: O(n*n*n)
    int func1(vector<pair<int, int>>& points) {
    	int ans = 0;
        for (int i = 0; i < points.size(); i++) {
        	for (int j = 0; j < points.size(); j++) {
        		if (j == i) continue;
        		for (int k = 0; k < points.size(); k++) {
        			if (k == i || k == j) continue;
        			if (d(points[i], points[j]) == 
        				d(points[i], points[k])) {
        				ans++;
        			}
        		}
        	}
        }
        return ans;
    }
    int d(pair<int, int> a, pair<int, int>b) {
    	return pow((a.first - b.first), 2) + pow((a.second - b.second), 2);
    }

    // hash map 
    // Time: O(n*n)
    // Space: O(n)
    int func2(vector<pair<int, int>>& points) {
    	int ans = 0;
    	for (int i = 0; i < points.size(); i++) {
    		unordered_map<int, int> map(points.size());
    		for (int j = 0; j < points.size(); j++) {
    			if (j == i) continue;
    			int dst = d(points[i], points[j]);
    			ans += 2 * map[dst]++;
    		}
    	}
    	return ans;
    }
};
