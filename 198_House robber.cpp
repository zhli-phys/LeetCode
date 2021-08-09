class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        vector<int> money(len);
        money[0] = nums[len - 1];
        money[1] = max(nums[len - 2], nums[len - 1]);
        for (int i = 2; i < len; i++)
            money[i] = max(nums[len - 1 - i] + money[i - 2], money[i - 1]);
        return money[len - 1];
    }
};