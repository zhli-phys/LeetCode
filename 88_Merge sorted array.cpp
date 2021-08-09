class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right1 = m - 1;
        int right2 = n - 1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (right2 < 0 || (right1 >= 0 && nums1[right1] >= nums2[right2])) {
                nums1[i] = nums1[right1];
                right1--;
            }
            else {
                nums1[i] = nums2[right2];
                right2--;
            }
        }
    }
};