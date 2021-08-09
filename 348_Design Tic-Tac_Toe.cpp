//52 ms
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n) {
        vector<vector<int>> temp(2*n+2, vector<int>(2, 0));
        sets = temp;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        sets[row][player-1]++;
        sets[n+col][player-1]++;
        if (sets[row][player-1] == n || sets[n+col][player-1] == n)
            return player;
        if (row == col) {
            sets[2*n][player-1]++;
            if (sets[2*n][player-1] == n)
                return player;
        }
        if (row + col == n-1) {
            sets[2*n+1][player-1]++;
            if (sets[2*n+1][player-1] == n)
                return player;
        }
        return 0;
    }
    
private:
    int n;
    vector<vector<int>> sets;
};








//32 ms
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), table(n, vector<int>(n)) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        table[row][col] = player;
        for (size_t i = 0; i < n; ++i) {
            if (table[i][col] != player)
                break;
            if (i == n - 1)
                return player;
        }
        for (size_t i = 0; i < n; ++i) {
            if (table[row][i] != player)
                break;
            if (i == n - 1)
                return player;
        }
        if (row == col) {
            for (size_t i = 0; i < n; ++i) {
                if (table[i][i] != player)
                    break;
                if (i == n - 1)
                    return player;
            }
        }
        if (row + col == n - 1) {
            for (size_t i = 0; i < n; ++i) {
                if (table[i][n-i-1] != player)
                    break;
                if (i == n - 1)
                    return player;
            }
        }
        return 0;
    }
    
private:
    int n;
    vector<vector<int>> table;
};

















//28 ms
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), count(4 * n + 4) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(++count[row + n * (player - 1)] == n)
            return player;
        if(++count[col + n * (player + 1)] == n)
            return player;
        if(row == col && ++count[4*n + player - 1] == n)
            return player;
        if(row + col == n - 1 && ++count[4*n + player + 1] == n)
            return player;
        return 0;
    }
    
private:
    int n;
    vector<int> count;
};

