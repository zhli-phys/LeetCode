class Solution {
public:
    bool canJump(vector<int>& nums) {
        int current = nums.size() - 1;
        for (int i = current - 1; i >= 0; i--) {
            if (current - i <= nums[i])
                current = i;
        }
        if (current > 0)
            return false;
        else
            return true;
    }
};