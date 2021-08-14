class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> filled(27, vector<bool>(9));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    filled[i][num] = true;
                    filled[j+9][num] = true;
                    filled[3*(i/3)+(j/3)+18][num] = true;
                }
            }
        }
        vector<int> path;
        dfs(0, board, path, filled);
    }
    
    bool dfs(int pos, vector<vector<char>>& board, vector<int>& path, vector<vector<bool>>& filled) {
        if (pos == 81)
            return true;
        int row = pos / 9;
        int col = pos % 9;
        int block = 3*(row/3)+(col/3);
        if (board[row][col] != '.')
            return dfs(pos + 1, board, path, filled);
        for (int curr = 0; curr < 9; ++curr) {
            if (filled[row][curr] || filled[9+col][curr] || filled[18+block][curr])
                continue;
            path.push_back(row*81+col*9+curr);
            filled[row][curr] = true;
            filled[9+col][curr] = true;
            filled[18+block][curr] = true;
            board[row][col] = '1' + curr;
            if (dfs(pos+1, board, path, filled))
                return true;
            board[row][col] = '.';
            filled[row][curr] = false;
            filled[9+col][curr] = false;
            filled[18+block][curr] = false;
            path.pop_back();
        }
        return false;
    }
};