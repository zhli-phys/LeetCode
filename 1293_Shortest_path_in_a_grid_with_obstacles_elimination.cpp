class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if (k >= m + n - 2)
            return m + n - 2;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX)));
        queue<pair<int, int>> q;
        q.push({0, 0});
        int step = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int s = 0; s < len; ++s) {
                int i = q.front().first / n;
                int j = q.front().first % n;
                int l = q.front().second;
                q.pop();
                if (dp[i][j][l] > step) {
                    for (int ll = l; ll <= k; ++ll)
                        dp[i][j][ll] = min(dp[i][j][ll], step);
                    for (auto& dir : dirs) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            int z = l + grid[x][y];
                            if (z <= k && dp[x][y][z] > step + 1) {
                                q.push({n * x + y, z});
                            }
                        }
                    }
                }
            }
            ++step;
        }
        return dp.back().back().back() == INT_MAX ? -1 : dp.back().back().back();
    }
};