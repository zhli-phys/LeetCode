class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < n; ++i) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(prev1, prev2);
    }
};












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