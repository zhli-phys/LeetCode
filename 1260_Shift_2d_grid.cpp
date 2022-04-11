class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        int s = m * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int pos = (n * i + j - k) % s;
                if (pos < 0)
                    pos += s;
                ans[i][j] = grid[pos/n][pos%n];
            }
        }
        return ans;
    }
};