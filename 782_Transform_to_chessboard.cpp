class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        auto origin = board;
        int n = board.size();
        int ones = accumulate(board[0].begin(), board[0].end(), 0);
        if (n % 2 == 0 && ones != n / 2) 
            return -1;
        if (n % 2 == 1 && ones != n / 2 && ones != n / 2 + 1)
            return -1;
        if (n % 2 == 1 && board[0][0] != ones - n / 2) {
            for (int j = 1; j < n; j += 2) {
                if (board[0][j] != board[0][0]) {
                    swapCol(0, j, board);
                    break;
                }                    
            }
        }
        int even = 0; 
        int odd = 1;
        while (even < n && odd < n) {
            if (board[0][even] == board[0][0])
                even += 2;
            else if (board[0][odd] != board[0][0])
                odd += 2;
            else {
                swapCol(even, odd, board);
                even += 2;
                odd += 2;
            }
        }
        
        ones = 0;
        for (int i = 0; i < n; ++i)
            ones += board[i][0];
        if (n % 2 == 0 && ones != n / 2) 
            return -1;
        if (n % 2 == 1 && ones != n / 2 && ones != n / 2 + 1)
            return -1;
        if (n % 2 == 1 && board[0][0] != ones - n / 2) {
            for (int i = 1; i < n; i += 2) {
                if (board[i][0] != board[0][0]) {
                    swap(board[0], board[i]);
                    break;
                }                    
            }
        }
        even = 0;
        odd = 1;
        while (even < n && odd < n) {
            if (board[even][0] == board[0][0])
                even += 2;
            else if (board[odd][0] != board[0][0])
                odd += 2;
            else {
                swap(board[even], board[odd]);
                even += 2;
                odd += 2;
            }
        }
        if (!check(board))
            return -1;
        
        vector<int> col(n);
        for (int j = 0; j < n; ++j)
            col[j] = origin[j][0];
        return steps(origin[0]) + steps(col); 
    }
    
    void swapCol(int j1, int j2, vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); ++i)
            swap(board[i][j1], board[i][j2]);
    }
    
    bool check(vector<vector<int>>& board) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != (i + j + board[0][0]) % 2)
                    return false;
            }
        }
        return true;
    }
    
    int steps(vector<int>& vec) {
        int n = vec.size();
        if (n % 2 == 1) {
            int ones = accumulate(vec.begin(), vec.end(), 0);
            return steps(vec, ones - n / 2);
        }
        else
            return min(steps(vec, 0), steps(vec, 1));
    }
    
    int steps(vector<int>& vec, int init) {
        int ans = 0;
        for (int i = 0; i < vec.size(); ++i)
            ans += (vec[i] + init + i) % 2;
        return ans / 2;
    }
};