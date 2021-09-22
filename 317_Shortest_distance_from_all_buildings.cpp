class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> currDist(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    int step = 0;
                    q.push({i, j});
                    while (!q.empty()) {                     
                        int len = q.size();
                        for (int k = 0; k < len; ++k) {
                            auto& currPos = q.front();
                            currDist[currPos.first][currPos.second] = step;
                            for (auto& dir : dirs) {
                                int x = currPos.first + dir.first;
                                int y = currPos.second + dir.second;
                                if (x >= 0 && x < m && y >= 0 && y < n) {
                                    if (grid[x][y] == 0 && currDist[x][y] == 0) {
                                        currDist[x][y] = step;
                                        q.push({x, y});
                                    }
                                }
                            }
                            q.pop();
                        }                        
                        ++step; 
                    }
                    for (int s = 0; s < m; ++s) {
                        for (int t = 0; t < n; ++t) {
                            if (dist[s][t] != INT_MAX) {
                                if (currDist[s][t] == 0)
                                    dist[s][t] = INT_MAX;
                                else 
                                    dist[s][t] += currDist[s][t];
                            }
                            currDist[s][t] = 0;
                        }
                    }
                }
            }
        }        
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = min(ans, dist[i][j]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


















// Time limit exceeded
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        vector<int> rows;
        vector<int> cols;
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) 
                    ++total;
            }
        }
        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int currDist = 0;
                    int step = 0;
                    int currCount = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 3;
                    while (currCount < total && !q.empty()) {
                        ++step;
                        int currLen = q.size();
                        for (int k = 0; k < currLen; ++k) {
                            auto& currPos = q.front();
                            for (auto& dir : dirs) {
                                int x = currPos.first + dir.first;
                                int y = currPos.second + dir.second;
                                if (x >= 0 && x < m && y >= 0 && y < n) {
                                    if (grid[x][y] == 1) {
                                        currDist += step;
                                        ++currCount;
                                        grid[x][y] = 4;
                                    }
                                    else if (grid[x][y] == 0) {
                                        q.push({x, y});
                                        grid[x][y] = 3;
                                    }
                                }
                            }
                            q.pop();
                        }
                    }
                    if (currCount == total)
                        ans = min(ans, currDist);
                    for (int s = 0; s < m; ++s) {
                        for (int t = 0; t < n; ++t) {
                            if (grid[s][t] == 3)
                                grid[s][t] = 0;
                            else if (grid[s][t] == 4)
                                grid[s][t] = 1;
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};