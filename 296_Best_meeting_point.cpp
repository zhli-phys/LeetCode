class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cols;
        vector<int> rows;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        int len = cols.size();
        sort(cols.begin(), cols.end());
        int midRow = len % 2 == 1 ? rows[len/2] : (rows[len/2 - 1] + rows[len/2]) / 2;
        int midCol = len % 2 == 1 ? cols[len/2] : (cols[len/2 - 1] + cols[len/2]) / 2;
        int ans = 0;
        for (int i = 0; i < len; ++i) 
            ans += abs(rows[i] - midRow) + abs(cols[i] - midCol) + 1e-7;
        return ans;
    }
};