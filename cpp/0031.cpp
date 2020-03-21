class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // func1(nums);
        return func2(nums);
    }

    void func1(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }

    void func2(vector<int>& nums) {
        int partition_index = findPartition(nums);
        if (partition_index == -1) {
            reverse(nums, 0, nums.size()-1);
            return;
        }
        int change_index = findChange(nums, partition_index);
        swap(nums, partition_index, change_index);
        reverse(nums, partition_index+1, nums.size() - 1);
    }

    // return partition number index
    int findPartition(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        // cout << "findPartition i=" << i << endl;
        return i;
    }
    // return change number index
    int findChange(vector<int>& nums, int partition_index) {
        int i = nums.size() - 1;
        while (i > partition_index && nums[i] <= nums[partition_index]) {
            i--;
        }
        // cout << "findChange i=" << i << endl;
        return i;
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }

    void reverse(vector<int>& nums, int lo, int hi) {
        while (lo < hi) {
            swap(nums, lo, hi);
            lo++;
            hi--;
        }
        return;
    }
};