class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lk = (nums1.size() + nums2.size() + 1) / 2;
        int rk = (nums1.size() + nums2.size() + 2) / 2;
        double lret = findKth(nums1, 0, nums2, 0, lk);
        double rret = findKth(nums1, 0, nums2, 0, rk);
        return (lret + rret) / 2;
    }
    double findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size()) {
            return nums2[j+k-1];
        }
        if (j >= nums2.size()) {
            return nums1[i+k-1];
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int val1 = (i+k/2-1 < nums1.size()) ? nums1[i+k/2-1] : INT_MAX;
        int val2 = (j+k/2-1 < nums2.size()) ? nums2[j+k/2-1] : INT_MAX;

        if (val1 < val2) {
            return findKth(nums1, i+k/2, nums2, j, k-k/2);
        } else {
            return findKth(nums1, i, nums2, j+k/2, k-k/2);
        }
    }
};
