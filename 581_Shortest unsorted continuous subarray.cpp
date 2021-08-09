class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty())
            return 0;
        int curr_max = nums[0];
        int right = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < curr_max)
                right = i;
            else
                curr_max = nums[i];
        }
        if (right < 0)
            return 0;
        int curr_min = nums[n - 1];
        int left = n;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > curr_min)
                left = i;
            else
                curr_min = nums[i];
        }
        return right - left + 1;
    }
};