//16 ms
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr_area = 0;
                dfs(i, j, grid, visited, curr_area, max_area);
            }
        }    
        return max_area;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& curr_area, int& max_area) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) 
            return;
        visited[i][j] = true;
        ++curr_area;
        max_area = max(max_area, curr_area);
        dfs(i - 1, j, grid, visited, curr_area, max_area);
        dfs(i + 1, j, grid, visited, curr_area, max_area);
        dfs(i, j - 1, grid, visited, curr_area, max_area);
        dfs(i, j + 1, grid, visited, curr_area, max_area);
    }
};



















//Modifies the original grid
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_area = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr_area = 0;
                dfs(i, j, grid, curr_area, max_area);
            }
        }    
        return max_area;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int& curr_area, int& max_area) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) 
            return;
        grid[i][j] = 0;
        ++curr_area;
        max_area = max(max_area, curr_area);
        dfs(i - 1, j, grid, curr_area, max_area);
        dfs(i + 1, j, grid, curr_area, max_area);
        dfs(i, j - 1, grid, curr_area, max_area);
        dfs(i, j + 1, grid, curr_area, max_area);
    }
};




















//52 ms
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_area = 0;
        int curr_area = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(i, j, max_area, grid, visited);
        return max_area;
    }
    
    int dfs(int i, int j, int& max_area, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0)
            return 0;
        visited[i][j] = true;
        int curr_area = 1 + dfs(i-1, j, max_area, grid, visited) 
            + dfs(i+1, j, max_area, grid, visited)
            + dfs(i, j-1, max_area, grid, visited)
            + dfs(i, j+1, max_area, grid, visited);
        max_area = max(max_area, curr_area);
        return curr_area;
    }
};
