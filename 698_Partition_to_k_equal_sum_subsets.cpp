class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        vector<unordered_map<int, bool>> dp(1 << n);
        dp.back()[0] = true;
        return check(0, 0, nums, sum / k, dp);
    }
    
    bool check(int curr, int bitmask, vector<int>& nums, int target, vector<unordered_map<int, bool>>& dp) {
        if (curr > target)
            return false;
        else if (curr == target)
            curr = 0;
        if (dp[bitmask].find(curr) != dp[bitmask].end())
            return dp[bitmask][curr];
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if ((bitmask & (1 << i)) == 0 && check(curr + nums[i], bitmask | (1 << i), nums, target, dp)) {
                dp[bitmask][curr] = true;
                return true;
            }
        }
        dp[bitmask][curr] = false;
        return false;
    }
};