class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // return func1(nums, target);
        // return func2(nums, target);
        return func3(nums, target);
    }

    // ** iterative
    int func1(vector<int>& nums, int target) {
        return helper1(nums, 0, target);
    }
    int helper1(vector<int>& nums, int sum, int target) {
        if (sum > target) {
            return 0;
        }
        if (sum == target) {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += helper1(nums, sum + nums[i], target);
        }
        return res;
    }

    // ** 1D array dp
    int func2(vector<int>& nums, int target) {
        // vector<int> dp(target+1, 0);
        // vector<unsigned int> dp(target+1, 0);
        // vector<unsigned long> dp(target+1, 0);
        // vector<double> dp(target+1, 0);
        vector<long double> dp(target+1, 0);
        for (auto n : nums) {
            if (n <= target) {
                dp[n] = 1;
            }
        }
        for (int i = 1; i <= target; i++) {
            for (auto n : nums) {
                if (i - n > 0) {
                    dp[i] += dp[i-n];
                }
            }
        }
        
        cout<< "size of int = " << sizeof(int) << endl;
        cout<< "size of unsigned int = " << sizeof(unsigned int) << endl;
        cout<< "size of long = " << sizeof(long) << endl;
        cout<< "size of long long =" << sizeof(long long) << endl;
        cout<< "size of double =" << sizeof(double) << endl;
        cout<< "size of long double =" << sizeof(long double) << endl << endl;
        
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt3 = 0;
        for (int i = 0; i <= target; i++) {
            // ** signed 4 Bytes integer max
            if (dp[i] > 2147483647) {
                cnt0++;
            }
            // ** unsigned 4 Bytes integer max
            if (dp[i] > 4294967295) {
                cnt1++;
            }
            // ** signed 8 Bytes integer max
            if (dp[i] > 9223372036854775807) {
                cnt2++;   
            }
            // ** unsigned 8 Bytes integer max
            if (dp[i] > 18446744073709551615) {
                cnt3++;
            }
        }
        
        cout << "numbers >2147483647 count = " << cnt0 << endl;
        cout << "numbers >4294967295 count = " << cnt1 << endl;
        cout << "numbers >9223372036854775807 count = " << cnt2 << endl;
        cout << "numbers >18446744073709551615 count = " << cnt3 << endl << endl;
        
        unsigned int x = 4294967295;
        cout << "x = " << x << endl;
        x += 1;
        cout << "x = " << x << endl;
        
        return dp[target];
    }

    // ** minus always better to plus in func1()
    // ** NO... also TLE at [1,2,3] 32
    int func3(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }

        int res = 0;
        for (auto n : nums) {
            if (target >= n) {
                res += func3(nums, target - n);
            }
        }

        return res;
    }
};
