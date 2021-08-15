class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n - i; ++k) {
                dp[i][i][k] = (k + 1) * (k + 1);
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int k = 0; k < n - j; ++k) {
                    dp[i][j][k] = dp[i][j-1][0] + (k + 1) * (k + 1);
                    for (int m = i; m < j; ++m) {
                        if (boxes[m] == boxes[j])
                            dp[i][j][k] = max(dp[i][j][k], dp[i][m][k+1] + dp[m+1][j-1][0]);
                    }
                }
            }
        }
        return dp[0][n-1][0];
    }
};