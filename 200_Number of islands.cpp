class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<bool> row(m, false);
        vector<vector<bool>> visited(n, row);
        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    set_visited(grid, visited, i, j);
                }
            }
        }
        return islands;
    }
    
    void set_visited(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        if (i > 0 && grid[i - 1][j] == '1' && !visited[i - 1][j])
            set_visited(grid, visited, i - 1, j);
        if (j > 0 && grid[i][j - 1] == '1' && !visited[i][j - 1])
            set_visited(grid, visited, i, j - 1);
        if (i < n - 1 && grid[i + 1][j] == '1' && !visited[i + 1][j])
            set_visited(grid, visited, i + 1, j);
        if (j < m - 1 && grid[i][j + 1] == '1' && !visited[i][j + 1])
            set_visited(grid, visited, i, j + 1);
    }
};