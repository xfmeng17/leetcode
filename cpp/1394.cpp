class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ret = -1;
        unordered_map<int, int> table;
        for (auto a : arr) {
            table[a]++;
        }
        for (auto it = table.begin(); it != table.end(); it++) {
            if (it->first == it->second) {
                ret = max(it->first, ret);
            }
        }
        return ret;
    }
};