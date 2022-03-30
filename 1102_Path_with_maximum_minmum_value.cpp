class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        used[0][0] = true;
        int target = m * n - 1;
        int minNum = grid[0][0];
        priority_queue<pair<int, int>> pq;
        pq.push({grid[0][0], 0});
        vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!pq.empty()) {
            int curr = pq.top().first;
            minNum = min(minNum, curr);
            int i = pq.top().second / n;
            int j = pq.top().second % n;
            pq.pop();
            if (i == m - 1 && j == n - 1)
                return minNum;
            for (auto& dir : dirs) {
                int nextI = i + dir[0];
                int nextJ = j + dir[1];
                if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && !used[nextI][nextJ]) {
                    used[nextI][nextJ] = true;
                    pq.push({grid[nextI][nextJ], n * nextI + nextJ});
                }
            }
        }
        return -1;
    }
};