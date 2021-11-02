class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int start;
        int target = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                switch(grid[i][j]) {
                    case 0:
                        ++target;
                        break;
                    case 1:
                        start = i * n + j;
                }
            }
        }
        unordered_set<int> path;
        return dfs(start, path, grid, target);
    }
    
    int dfs(int curr, unordered_set<int>& path, vector<vector<int>>& grid, int target) {
        if (path.find(curr) != path.end())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int i = curr / n;
        int j = curr % n;
        switch(grid[i][j]) {
            case -1:
                return 0;
            case 2:
                return path.size() == target;
            default:
                path.insert(curr);
                int ans = 0;
                if (i > 0)
                    ans += dfs(curr - n, path, grid, target);
                if (i < m - 1)
                    ans += dfs(curr + n, path, grid, target);
                if (j > 0)
                    ans += dfs(curr - 1, path, grid, target);
                if (j < n - 1)
                    ans += dfs(curr + 1, path, grid, target);
                path.erase(curr);
                return ans;
        }
    }
};