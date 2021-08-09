class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int j = nums[i];
            if (j > 0 && j <= len && j != i + 1) {
                adjust(nums, j - 1);
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return len + 1;
    }
    
    void adjust(vector<int>& nums, int i) {
        int j = nums[i];
        nums[i] = i + 1;
        if (j > 0 && j <= nums.size() && j != i + 1) 
            adjust(nums, j - 1);
    }
};