pair<int, int> operator+(pair<int, int>& lhs, pair<int, int>& rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

class Solution {
public:
    int minKnightMoves(int x, int y) {
        vector<vector<bool>> visited(700, vector(700, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[350][350] = true;
        int step = 0;
        vector<pair<int, int>> moves{{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
        while (true) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto& curr = q.front();
                if (curr.first == x && curr.second == y)
                    return step;
                for (auto& move : moves) {
                    auto next = curr + move;
                    if (next.first > - 340 && next.first < 340 
                        && next.second > -340 && next.second < 340
                        && !visited[next.first+350][next.second+350]) {
                        q.push(next);
                        visited[next.first+350][next.second+350] = true;
                    }
                }
                q.pop();
            }
            ++step;
        }
        return step;
    }
};

















pair<int, int> operator+(pair<int, int>& lhs, pair<int, int>& rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x < 0)
            x = -x;
        if (y < 0)
            y = -y;
        vector<vector<bool>> visited(x+4, vector<bool>(y+4, false));
        vector<pair<int, int>> moves{{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        visited[1][1] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int step = 0;
        while (true) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto& curr = q.front();
                if (curr.first == x && curr.second == y)
                    return step;
                for (auto& move : moves) {
                    auto next = curr + move;
                    if (next.first >= -1 && next.first <= x+2 
                       && next.second >= -1 && next.second <= y+2
                       && !visited[next.first+1][next.second+1]) {
                        q.push(next);
                        visited[next.first+1][next.second+1] = true;
                    }
                }
                q.pop();
            }
            ++step;
        }
        return step;
    }
};















class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = x >= 0 ? x : -x;
        y = y >= 0 ? y : -y;
        vector<vector<int>> dp(x+3, vector<int>(y+3, -1));
        dp[0][0] = 0;
        dp[0][1] = dp[1][0] = 3;
        dp[1][1] = 2;
        return min_moves(x, y, dp);
    }
    
    int min_moves(int x, int y, vector<vector<int>>& dp) {
        x = x >= 0 ? x : -x;
        y = y >= 0 ? y : -y;
        if (dp[x][y] >= 0)
            return dp[x][y];
        dp[x][y] = min(min_moves(x-1, y-2, dp), min_moves(x-2, y-1, dp)) + 1;
        return dp[x][y];
    }
};