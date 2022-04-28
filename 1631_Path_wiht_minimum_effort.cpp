class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int minHeight = INT_MAX;
        int maxHeight = INT_MIN;
        for (auto& height : heights) {
            for (int h : height) {
                minHeight = min(minHeight, h);
                maxHeight = max(maxHeight, h);
            }
        }
        
        int left = 0;
        int right = maxHeight - minHeight;
        while (left < right) {
            int mid = (left + right) / 2;
            if (accessible(mid, heights))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
    bool accessible(int diff, vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        return dfs(0, 0, diff, heights, visited);
    }
    
    bool dfs(int i, int j, int diff, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int m = heights.size();
        int n = heights[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return false;
        visited[i][j] = true;
        if (i == m - 1 && j == n - 1)
            return true;
        for (int k = 0; k < 4; ++k) {
            int newI = i + dirs[k][0];
            int newJ = j + dirs[k][1];
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n 
                && abs(heights[i][j] - heights[newI][newJ]) <= diff 
                && dfs(newI, newJ, diff, heights, visited))
                return true;
        }
        return false;
    }
};