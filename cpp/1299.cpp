class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curr_max = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int temp = arr[i];
            arr[i] = curr_max;
            curr_max = max(curr_max, temp);
        }
        return arr;
    }
};