//graph algorithm; O(n^2 log n) 20 ms 61%; O(n^2) 10.9 MB 34%
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                pos[grid[i][j]] = {i, j};
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(grid[0][0]);
        int target = grid[n-1][n-1];
        int ans = grid[0][0];
        unordered_set<int> visited;
        visited.insert(grid[0][0]);
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (pq.top() != target) {
            ans = max(ans, pq.top());
            auto& p = pos[pq.top()];
            pq.pop();
            for (auto& dir : dirs) {
                int x = p.first + dir[0];
                int y = p.second + dir[1];
                if (x >= 0 && x < n && y >= 0 && y < n && visited.find(grid[x][y]) == visited.end()) {
                    pq.push(grid[x][y]);
                    visited.insert(grid[x][y]);
                }
            }
        }
        return max(ans, target);
    }
};