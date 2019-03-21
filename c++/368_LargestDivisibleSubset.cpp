class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // return func1(nums);
        // return func2(nums);
        return func3(nums);
    }


    // ** naive try, iterate
    // ** O(n^3)
    vector<int> func1(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) {
            return vector<int>(nums);
        }
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        for (int i = 0; i < N; i++) {

            vector<int> aux;
            aux.push_back(nums[i]);

            for (int j = 0; j < N; j++) {
                if (j == i) { continue; }
                bool pick = true;
                for (auto x : aux) {
                    if ((x % nums[j] != 0) && (nums[j] % x != 0)) {
                        pick = false;
                        break;
                    }
                }
                if (pick) {
                    aux.push_back(nums[j]);
                }
            }

            if (aux.size() > res.size()) {
                res = aux;
            }
        }

        return res;
    }

    // ** sort + two pointer
    // ** O(n^2)
    vector<int> func2(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) {
            return vector<int>(nums);
        }

        sort(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < N; i++) {

            vector<int> aux;
            aux.push_back(nums[i]);
            int lf = nums[i];
            int rt = nums[i];
            for (int j = i-1; j >= 0; j--) {
                if (lf % nums[j] == 0) {
                    aux.push_back(nums[j]);
                    lf = nums[j];
                }
            }
            for (int j = i+1; j < N; j++) {
                if (nums[j] % rt == 0) {
                    aux.push_back(nums[j]);
                    rt = nums[j];
                }
            }
            if (aux.size() > res.size()) {
                res = aux;
            }
        }

        return res;
    }

    // ** same with func2 but reduce space using
    vector<int> func3(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) {
            return vector<int>(nums);
        }
        sort(nums.begin(), nums.end());
        int idx = 0;
        int len = 0;

        for (int i = 0; i < N; i++) {
            int cnt = 1;
            int lf = nums[i];
            for (int j = i-1; j >= 0; j--) {
                if (lf % nums[j] == 0) {
                    lf = nums[j];
                    cnt++;
                }
            }
            int rt = nums[i];
            for (int j = i+1; j < N; j++) {
                if (nums[j] % rt == 0) {
                    rt = nums[j];
                    cnt++;
                }
            }
            if (cnt > len) {
                idx = i;
                len = cnt;
            }
        }

        vector<int> res;
        res.push_back(nums[idx]);
        int lf = nums[idx];
        for (int j = idx-1; j >= 0; j--) {
            if (lf % nums[j] == 0) {
                res.push_back(nums[j]);
                lf = nums[j];
            }
        }
        int rt = nums[idx];
        for (int j = idx+1; j < N; j++) {
            if (nums[j] % rt == 0) {
                res.push_back(nums[j]);
                rt = nums[j];
            }
        }

        return res;
    }
};
