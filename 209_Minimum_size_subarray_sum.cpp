class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int currSum = 0;
        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            currSum += nums[j];
            if (currSum >= target) {
                while (i <= j && currSum - nums[i] >= target) {
                    currSum -= nums[i];
                    ++i;
                }
                ans = min(ans, j - i + 1);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};