class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> used(27, vector<bool>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    used[i][num] = true;
                    used[j+9][num] = true;
                    used[3*(i/3)+j/3+18][num] = true;
                }
            }
        }
        dfs(0, board, used);
    }
    
    bool dfs(int pos, vector<vector<char>>& board, vector<vector<bool>>& used) {
        if (pos >= 81)
            return true;
        int i = pos % 9;
        int j = pos / 9;
        if (board[i][j] != '.')
            return dfs(pos+1, board, used);
        int block = 3 * (i / 3) + j / 3;
        for (int num = 0; num < 9; ++num) {
            if (used[i][num] || used[j+9][num] || used[block+18][num])
                continue;
            board[i][j] = '1' + num;
            used[i][num] = true;
            used[j+9][num] = true;
            used[block+18][num] = true;
            if (dfs(pos+1, board, used))
                return true;
            used[block+18][num] = false;
            used[j+9][num] = false;
            used[i][num] = false;
            board[i][j] = '.';
        }
        return false;
    }
};