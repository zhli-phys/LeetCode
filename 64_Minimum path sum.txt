class Solution {
public:   
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sums(m);
        for (int i = 0; i < m; i++) {
            vector<int> temp(n, -1);
            sums[i] = temp;
        }
        return minPathSum(grid, sums, 0, 0);
    }
    
    int minPathSum(vector<vector<int>>& grid, vector<vector<int>>& sums, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (sums[i][j] >= 0)
            return sums[i][j];
        if (i < m - 1 && j < n - 1) {
            int sol = grid[i][j] + min(minPathSum(grid, sums, i + 1, j), minPathSum(grid, sums, i, j + 1));
            sums[i][j] = sol;
            return sol;
        }
        if (i < m - 1) {
            int sol = grid[i][j] + minPathSum(grid, sums, i + 1, j);
            sums[i][j] = sol;
            return sol;
        }
        if (j < n - 1) {
            int sol = grid[i][j] + minPathSum(grid, sums, i, j + 1);
            sums[i][j] = sol;
            return sol;
        }
        int sol = grid[i][j];
        sums[i][j] = sol;
        return sol;
    }
};