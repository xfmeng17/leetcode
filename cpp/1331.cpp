class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ret(arr.size(), 0);
        vector<int> aux(arr.begin(), arr.end());
        sort(aux.begin(), aux.end());
        int cnt = 0;
        vector<int> uqi;
        for (int i = 0; i < aux.size(); i++) {
            if (cnt > 0 && uqi[cnt-1] == aux[i]) {
                continue;
            }
            cnt++;
            uqi.emplace_back(aux[i]);
        }
        
        for (int i = 0 ; i < arr.size(); i++) {
            ret[i] = bs(uqi, arr[i]) + 1;
        }
        return ret;
    }
    
    int bs(vector<int>& uqi, int target) {
        int lo = 0;
        int hi = uqi.size() - 1;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (uqi[mid] == target) {
                return mid;
            } else if (uqi[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return -1;
    }
};