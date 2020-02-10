class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if (k > n) {
            return 0;
        }

        int ret = 0;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if (sum / k >= threshold) {
            ret++;
        }

        for (int i = k; i < n; i++) {
            sum = sum - arr[i-k] + arr[i];
            if (sum / k >= threshold) {
                ret++;
            }
        }

        return ret;
    }
};