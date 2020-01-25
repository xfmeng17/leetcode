class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        // return func1(arr, target);
        // return func2(arr, target);
        return func3(arr, target);
    }


    // my binary search
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

        for (int k = 0; k <= arr[N-1]; k++) {
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
    
    // my binary search. more readable
    int func2(vector<int>& arr, int target) {
        int N = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> sum(N, 0);
        sum[0] = arr[0];
        for (int i = 1; i < N; i++) {
            sum[i] = arr[i] + sum[i-1];
        }
        int min_val = arr[N-1] + 1;
        int min_key = -1;

        for (int k = 0; k <= arr[N-1]; k++) {
            int idx = largetLessEqualBS(arr, k);
            int val = 0;
            if (idx == -1) {
                val = N * k;
            } else if (idx == N-1) {
                val = sum[N-1];
            } else {
                val = sum[idx] + (N - idx - 1) * k;
            }
            if (min_val > abs(target - val)) {
                min_val = abs(target - val);
                min_key = k;
            }
            if (min_val == 0) {
                return min_key;
            }
        }
        return min_key;
    }
    int largetLessEqualBS(vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return hi;
    }

    // reference
    int func3(vector<int>& arr, int target) {
        int lo = 0;
        int hi = 100001;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int sum = helper3(arr, mid);
            if (sum == target) {
                hi = mid - 1;
            } else if (sum < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        // printf("lo=%d, hi=%d\n", lo, hi);
        int sum_lo = helper3(arr, lo);
        int sum_hi = helper3(arr, hi);
        return abs(target - sum_lo) < abs(target - sum_hi) ? lo : hi;

    }
    int helper3(vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += min(arr[i], k);
        }
        return sum;
    }
};