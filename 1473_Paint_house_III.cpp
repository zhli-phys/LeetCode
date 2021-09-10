class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(target, -1)));
        if (houses[0] == 0) 
            for (int j = 0; j < n; ++j)
                dp[0][j][0] = cost[0][j];
        else
            dp[0][houses[0]-1][0] = 0;
        for (int i = 1; i < m; ++i) {
            if (houses[i] == 0) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i-1][j][0] >= 0)
                        dp[i][j][0] = dp[i-1][j][0] + cost[i][j];
                    for (int k = 1; k < target; ++k) {
                        if (dp[i-1][j][k] >= 0)
                            dp[i][j][k] = dp[i-1][j][k] + cost[i][j];
                        for (int jj = 0; jj < n; ++jj) {
                            if (j != jj && dp[i-1][jj][k-1] >= 0) {
                                if (dp[i][j][k] < 0)
                                    dp[i][j][k] = dp[i-1][jj][k-1] + cost[i][j];
                                else
                                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][jj][k-1] + cost[i][j]);
                            }
                        }
                    }
                }
            }
            else {
                int j = houses[i] - 1;
                if (dp[i-1][j][0] >= 0)
                    dp[i][j][0] = dp[i-1][j][0];
                for (int k = 1; k < target; ++k) {
                    if (dp[i-1][j][k] >= 0)
                        dp[i][j][k] = dp[i-1][j][k];
                    for (int jj = 0; jj < n; ++jj) {
                        if (j != jj && dp[i-1][jj][k-1] >= 0) {
                            if (dp[i][j][k] < 0)
                                dp[i][j][k] = dp[i-1][jj][k-1];
                            else
                                dp[i][j][k] = min(dp[i][j][k], dp[i-1][jj][k-1]);
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int j = 0; j < n; ++j) {
            if (dp[m-1][j][target-1] >= 0) {
                if (ans < 0)
                    ans = dp[m-1][j][target-1];
                else
                    ans = min(ans, dp[m-1][j][target-1]);
            }            
        }
        return ans;
    }
};