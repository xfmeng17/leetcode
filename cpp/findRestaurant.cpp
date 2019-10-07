class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> map;
		for (int i = 0; i < list1.size(); i++) {
			map.insert(make_pair(list1[i], i));
		}
		vector<string> ans;
		int indexSum = list1.size() + list2.size() + 1;
		unordered_map<string, int>::iterator got;
		for (int i = 0; i < list2.size(); i++) {	
			got = map.find(list2[i]);
			if (got != map.end()) {
				int indexCur = got->second + i;
				if (indexCur == indexSum) {
					ans.push_back(got->first);
				} else if (indexCur < indexSum) {
					indexSum = indexCur;
					ans.clear();
					ans.push_back(list2[i]);
				} else {
					// just pass by
				}
			}
		}
		return ans;
    }
};
