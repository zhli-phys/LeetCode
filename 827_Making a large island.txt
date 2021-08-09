//dfs; O(n^2) 364 ms 95%; O(n^2) 84 MB 96%
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> island(n, vector<int>(n, -1));
        int islandNum = 0;
        vector<int> islandArea;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && island[i][j] == -1) {
                    islandArea.push_back(dfs(i, j, grid, island, islandNum));
                    ++islandNum;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    vector<int> used;
                    ans = max(ans, 1 + area(i-1, j, island, islandArea, used) 
                              + area(i+1, j, island, islandArea, used)
                              + area(i, j-1, island, islandArea, used) 
                              + area(i, j+1, island, islandArea, used));
                }
                else
                    ans = max(ans, islandArea[island[i][j]]);
            }
        }
        return ans;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& island, int islandNum) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || island[i][j] >= 0)
            return 0;
        island[i][j] = islandNum;
        return 1 + dfs(i-1, j, grid, island, islandNum) + dfs(i+1, j, grid, island, islandNum)
            + dfs(i, j-1, grid, island, islandNum) + dfs(i, j+1, grid, island, islandNum);
    }
    
    int area(int i, int j, vector<vector<int>>& island, vector<int>& islandArea, vector<int>& used) {
        int n = island.size();
        if (i < 0 || i >= n || j < 0 || j >= n || island[i][j] == -1)
            return 0;
        int curr = island[i][j];
        for (int num : used) {
            if (num == curr)
                return 0;
        }
        used.push_back(curr);
        return islandArea[curr];
    }
};