//dynamic programming; O(n^2) 432 ms 10%; O(n^2) 85.3 MB 12%
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre_sums(n+1);
        for (int i = 1; i <= n; ++i)
            pre_sums[i] = pre_sums[i-1] + stones[i-1];
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return max_diff(0, n - 1, pre_sums, dp);
    }
    
    int max_diff(int left, int right, vector<int>& pre_sums, vector<vector<int>>& dp) {
        if (left > right)
            return 0;
        if (dp[left][right] >= 0)
            return dp[left][right];
        int remove_left = pre_sums[right+1] - pre_sums[left+1] - max_diff(left + 1, right, pre_sums, dp);
        int remove_right = pre_sums[right] - pre_sums[left] - max_diff(left, right - 1, pre_sums, dp);
        dp[left][right] = max(remove_left, remove_right);
        return dp[left][right];
    }
};