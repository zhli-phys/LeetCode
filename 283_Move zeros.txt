class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prevzero = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0)
                prevzero++;
            else if (prevzero > 0)
                nums[i - prevzero] = nums[i];
        }
        for (int i = len - prevzero; i < len; i++)
            nums[i] = 0;
    }
};