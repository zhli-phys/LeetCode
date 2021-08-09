class Solution {
public:
    int live(int i, int j, vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        else
            return board[i][j];
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> copy(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = live(i-1, j-1, board) + live(i-1, j, board) + live(i-1, j+1, board) 
                    + live(i, j-1, board) + live(i, j+1, board) + live(i+1, j-1, board) + live(i+1, j, board)
                    + live(i+1, j+1, board);
                if (count == 3)
                    copy[i][j] = 1;
                else if (board[i][j] == 1 && count == 2)
                    copy[i][j] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                board[i][j] = copy[i][j];
        }
    }
};

//In-place modification
class Solution {
public:
    int live(int i, int j, vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;
        else
            return board[i][j] % 2;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = live(i-1, j-1, board) + live(i-1, j, board) + live(i-1, j+1, board) 
                    + live(i, j-1, board) + live(i, j+1, board) + live(i+1, j-1, board) + live(i+1, j, board)
                    + live(i+1, j+1, board);
                if (board[i][j] == 1 && (count < 2 || count > 3))
                    board[i][j] = 3;
                else if (board[i][j] == 0 && count == 3)
                    board[i][j] = 2;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
};