//Dijkstra algorithm and priority queue; 100 ms 21%; 23.9 MB 34%
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> row_bars(m);
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (maze[i][j] == 1)
                    row_bars[i].push_back(j);
        vector<vector<int>> col_bars(n);
        for (int j = 0; j < n; ++j) 
            for (int i = 0; i < m; ++i)
                if (maze[i][j] == 1)
                    col_bars[j].push_back(i);
        vector<vector<int>> dist(m, vector<int>(n, -1));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, start[0], start[1]});
        while (!pq.empty()) {
            auto& curr = pq.top();
            int i = curr[1];
            int j = curr[2];
            int curr_dist = curr[0];
            pq.pop();
            if (dist[i][j] >= 0)
                continue;
            dist[i][j] = curr_dist;
            if (i == destination[0] && j == destination[1])
                break;
            
            int next;
            
            //move rightward
            auto& vec_row = row_bars[i];
            auto it = upper_bound(vec_row.begin(), vec_row.end(), j);
            if (it == vec_row.end())
                next = n - 1;
            else
                next = *it - 1;
            if (dist[i][next] < 0) 
                pq.push({curr_dist + next - j, i, next});
            
            //move leftward
            if (it == vec_row.begin())
                next = 0;
            else
                next = *(--it) + 1;
            if (dist[i][next] < 0)
                pq.push({curr_dist + j - next, i, next});
            
            //move upward
            auto& vec_col = col_bars[j];
            it = upper_bound(vec_col.begin(), vec_col.end(), i);
            if (it == vec_col.end())
                next = m - 1;
            else
                next = *it - 1;
            if (dist[next][j] < 0)
                pq.push({curr_dist + next - i, next, j});
            
            //move downward
            if (it == vec_col.begin())
                next = 0;
            else
                next = *(--it) + 1;
            if (dist[next][j] < 0)
                pq.push({curr_dist + i - next, next, j});
        }
        return dist[destination[0]][destination[1]];
    }
};



















//Dijkstra algorithm and priority queue; 112 ms 19%; 24.1 MB 33%
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> row_bars(m);
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (maze[i][j] == 1)
                    row_bars[i].push_back(j);
        vector<vector<int>> col_bars(n);
        for (int j = 0; j < n; ++j) 
            for (int i = 0; i < m; ++i)
                if (maze[i][j] == 1)
                    col_bars[j].push_back(i);
        vector<vector<int>> dist(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, start[0], start[1]});
        dist[start[0]][start[1]] = 0;
        while (!pq.empty()) {
            auto& curr = pq.top();
            int i = curr[1];
            int j = curr[2];
            int curr_dist = curr[0];
            pq.pop();
            if (visited[i][j])
                continue;
            dist[i][j] = curr_dist;
            visited[start[0]][start[1]] = true;
            if (i == destination[0] && j == destination[1])
                break;
            
            int next;
            
            //move rightward
            auto& vec_row = row_bars[i];
            auto it = upper_bound(vec_row.begin(), vec_row.end(), j);
            if (it == vec_row.end())
                next = n - 1;
            else
                next = *it - 1;
            if (dist[i][next] < 0 || dist[i][next] > curr_dist + next - j) {
                pq.push({curr_dist + next - j, i, next});
                dist[i][next] = curr_dist + next - j;
            }
                            
            //move leftward
            if (it == vec_row.begin())
                next = 0;
            else
                next = *(--it) + 1;
            if (dist[i][next] < 0 || dist[i][next] > curr_dist + j - next) {
                pq.push({curr_dist + j - next, i, next});
                dist[i][next] = curr_dist + j - next;
            }
            
            //move upward
            auto& vec_col = col_bars[j];
            it = upper_bound(vec_col.begin(), vec_col.end(), i);
            if (it == vec_col.end())
                next = m - 1;
            else
                next = *it - 1;
            if (dist[next][j] < 0 || dist[next][j] > curr_dist + next - i) {
                pq.push({curr_dist + next - i, next, j});
                dist[next][j] = curr_dist + next - i;
            }
            
            //move downward
            if (it == vec_col.begin())
                next = 0;
            else
                next = *(--it) + 1;
            if (dist[next][j] < 0 || dist[next][j] > curr_dist + i - next) {
                pq.push({curr_dist + i - next, next, j});
                dist[next][j] = curr_dist + i - next;
            }
        }
        return dist[destination[0]][destination[1]];
    }
};