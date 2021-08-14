class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_len = 1;
        int curr_len = 1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                ++curr_len;
                max_len = max(max_len, curr_len);
            }
            else {
                curr_len = 1;
            }
        }
        return max_len;
    }
};