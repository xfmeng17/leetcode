class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        return func1(arr, target);
    }

    int func1(vector<int>& arr, int target) {
        int N = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> sum(N, 0);
        for (int i = 0; i < N; i ++) {
            if (i == 0) {
                sum[i] = 0;
                continue;
            }
            sum[i] = sum[i-1] + arr[i-1]; 
            // printf("sum[%d]=%d\n", i, sum[i]);
        }
        
        int min_val = target + 1;
        int min_key = 0;

        for (int k = target/N; k <= sum[N-1]+arr[N-1]; k++) {
            int pos = binarySearch(arr, k);
            int diff = 0;
            if (pos >= N) {
                diff = sum[N-1] + arr[N-1];
            } else if (pos <= 0) {
                diff = N * k;
            } else {
                diff = sum[pos] + (N-pos) * k;
            }
            // printf("k=%d, pos=%d, diff=%d\n", k, pos, diff);
            if (min_val > abs(target - diff)) {
                min_val = abs(target - diff);
                min_key = k;
            }
            // if (k == 9150) {
            //     printf("k=%d, pos=%d, diff=%d\n", k, pos, diff);
            // }
            if (min_val == 0) {
                return min_key;
            }
        }

        return min_key;
    }

    int binarySearch(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};