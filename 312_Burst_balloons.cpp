class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        return maxCoins(nums, 0, n-1, dp);
    }
    
    int maxCoins(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] > 0)
            return dp[i][j];
        int left = i > 0 ? nums[i-1] : 1;
        int right = j < nums.size() - 1 ? nums[j+1] : 1;
        if (i == j) {
            dp[i][j] = left * nums[i] * right;
            return dp[i][j];
        }
        for (int k = i; k <= j; ++k) {
            dp[i][j] = max(dp[i][j], 
                           maxCoins(nums, i, k - 1, dp) + maxCoins(nums, k + 1, j, dp) + left * nums[k] * right);
        }
        return dp[i][j];
    }
};