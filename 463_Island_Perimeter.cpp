class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    for (int k = 0; k < 4; ++k) {
                        int next_i = i + dirs[k][0];
                        int next_j = j + dirs[k][1];
                        if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && grid[next_i][next_j] == 1)
                            ans -= 1;
                    }
                }
            }
        }
        return ans;
    }
};