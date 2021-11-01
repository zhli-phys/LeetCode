class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(i, 0, board);
            dfs(i, n-1, board);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, board);
            dfs(m-1, j, board);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'E')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void dfs(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return;
        board[i][j] = 'E';
        dfs(i-1, j, board);
        dfs(i+1, j, board);
        dfs(i, j-1, board);
        dfs(i, j+1, board);
    }
};












class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<bool>> bad(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (surrounded(i, j, board, visited, bad))
                        flip(i, j, board);
                    else
                        mark(i, j, board, bad);
                }
            }
        }
    }
    
    bool surrounded(int i, int j, vector<vector<char>>& board, 
                    vector<vector<bool>>& visited, vector<vector<bool>>& bad) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || bad[i][j])
            return false;
        if (board[i][j] == 'X' || visited[i][j])
            return true;
        visited[i][j] = true;
        for (auto& dir : dirs) {
            if (!surrounded(i + dir[0], j + dir[1], board, visited, bad))
                return false;
        }
        return true;
    }
    
    void flip(int i, int j, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X')
            return;
        board[i][j] = 'X';
        for (auto& dir : dirs) {
            flip(i + dir[0], j + dir[1], board);
        }
    }
    
    void mark(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& bad) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X' || bad[i][j])
            return;
        bad[i][j] = true;
        for (auto& dir : dirs) {
            mark(i + dir[0], j + dir[1], board, bad);
        }
    }
};