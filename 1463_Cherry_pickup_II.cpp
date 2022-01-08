class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[3] = {-1, 0, 1};
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 2, vector<int>(n + 2)));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k) {
                    int next = 0;
                    for (int dir1 : dirs) 
                        for (int dir2 : dirs)
                            next = max(next, dp[i+1][j+dir1][k+dir2]);
                    if (j == k)
                        dp[i][j][k] = next + grid[i][j-1];
                    else
                        dp[i][j][k] = next + grid[i][j-1] + grid[i][k-1];
                }
            }
        }
        return dp[0][1][n];
    }
};