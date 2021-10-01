class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        int ans = 0;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                dp[i][j] = dp[i-1][j-1] + (text1[i-1] == text2[j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                ans = max(ans, dp[i][j]);               
            }
        }
        return ans;
    }
};