class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> islands;
        vector<vector<bool>> visited(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(i, j, grid, visited, islands, count);
            }
        }
        return count;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, 
             vector<pair<int, int>>& islands, int& count) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 ||j >= n || grid[i][j] == 0 || visited[i][j])
            return;
        bool unique = true;
        int size = 0;
        mark(i, j, grid, visited, size);
        for (auto& island : islands) {
            if (size == island.second) {
                vector<vector<bool>> currVisited(m, vector<bool>(n));
                if (sameIsland(i, j, island.first / n, island.first % n, grid, currVisited)) {
                    unique = false;
                    break;
                }
            }            
        }
        if (unique) {
            ++count;
            islands.push_back({n * i + j, size});
        }        
    }
    
    bool sameIsland(int i, int j, int k, int l, vector<vector<int>>& grid, vector<vector<bool>>& currVisited) {
        int m = grid.size();
        int n = grid[0].size();
        if (num(i, j, grid) != num(k, l, grid))
            return false;
        if (used(i, j, currVisited))
            return true;
        if (i >= 0 && i < m && j >= 0 && j < n)
            currVisited[i][j] = true;
        if (num(i, j, grid) == 0) 
            return true;
        else
            return sameIsland(i-1, j, k-1, l, grid, currVisited) && sameIsland(i+1, j, k+1, l, grid, currVisited)
                    && sameIsland(i, j-1, k, l-1, grid, currVisited) && sameIsland(i, j+1, k, l+1, grid, currVisited);
    }
    
    inline int num(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        else
            return grid[i][j];
    }
    
    inline bool used(int i, int j, vector<vector<bool>>& currVisited) {
        int m = currVisited.size();
        int n = currVisited[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return true;
        else
            return currVisited[i][j];
    }
    
    void mark(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& size) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return;
        visited[i][j] = true;
        ++size;
        mark(i - 1, j, grid, visited, size);
        mark(i + 1, j, grid, visited, size);
        mark(i, j - 1, grid, visited, size);
        mark(i, j + 1, grid, visited, size);
    }
};