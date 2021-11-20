class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() / 2;
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[2 * mid] == nums[2 * mid + 1]) 
                left = mid + 1;
            else
                right = mid;
        }
        return nums[2 * left];
    }
};