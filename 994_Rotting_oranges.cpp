class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int numFresh = 0;
        queue<int> rotten;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1)
                    ++numFresh;
                else if (grid[i][j] == 2) 
                    rotten.push(i * n + j);
            }
        }
        if (numFresh == 0)
            return 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minute = 0;
        while (!rotten.empty()) {
            int oldNumFresh = numFresh;
            ++minute;
            int len = rotten.size();
            for (int k = 0; k < len; ++k) {
                int i = rotten.front() / n;
                int j = rotten.front() % n;
                rotten.pop();
                for (auto&& dir : dirs) {
                    int nextI = i + dir[0];
                    int nextJ = j + dir[1];
                    if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n && grid[nextI][nextJ] == 1) {
                        grid[nextI][nextJ] = 2;
                        --numFresh;
                        rotten.push(nextI * n + nextJ);
                    }
                }
            }
            if (numFresh == 0)
                return minute;
            else if (numFresh == oldNumFresh)
                return -1;
        }
        return -1;
    }
};