class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> blocks(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if (rows[i][num])
                    return false;
                rows[i][num] = true;
                if (cols[j][num])
                    return false;
                cols[j][num] = true;
                int block = (i / 3) * 3 + (j / 3);
                if (blocks[block][num])
                    return false;
                blocks[block][num] = true;
            }
        }
        return true;
    }
};











class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!helper(board[i]))
                return false;
        }
        vector<char> chars(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                chars[j] = board[j][i];
            if (!helper(chars))
                return false;
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                chars[0] = board[i][j];
                chars[1] = board[i][j+1];
                chars[2] = board[i][j+2];
                chars[3] = board[i+1][j];
                chars[4] = board[i+1][j+1];
                chars[5] = board[i+1][j+2];
                chars[6] = board[i+2][j];
                chars[7] = board[i+2][j+1];
                chars[8] = board[i+2][j+2];
                if (!helper(chars))
                return false;
            }
        }
        return true;
    }
    
    bool helper(vector<char>& chars) {
        vector<int> counts(9, 0);
        for (int i = 0; i < 9; i++) {
            int num = (chars[i] - '1');
            if (num >= 0 && ++counts[num] > 1) 
                return false;
        }
        return true;
    }
};