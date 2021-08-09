//4 ms, 6.1 MB
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> path(n, -1);
        for (int i = 0; i < n; ++i)
            dfs(0, i, n, path, count);
        return count;
    }
    
    void dfs(int row, int i, int n, vector<int>& path, int& count) {
        for (int r = 0; r < row; ++r) {
            if (i == path[r] || i == path[r] + row - r || i == path[r] + r - row)
                return;
        }
        if (row == n - 1)
            ++count;
        else {
            path[row] = i;
            for (int j = 0; j < n; ++j) 
                dfs(row + 1, j, n, path, count);
        }
    }
};










//0 ms, 5.9 MB, save used columns and diagonals
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> used(5 * n - 2, false);
        for (int col = 0; col < n; ++col)
            dfs(0, col, n, used, count);
        return count;
    }
    
    void dfs(int row, int col, int n, vector<bool>& used, int& count) {
        int diag1 = row - col + 2 * n - 1;
        int diag2 = row + col + 3 * n - 1;
        if (used[col] || used[diag1] || used[diag2])
            return;
        else if (row == n - 1)
            ++count;
        else {
            used[col] = true;
            used[diag1] = true;
            used[diag2] = true;
            for (int j = 0; j < n; ++j) 
                dfs(row + 1, j, n, used, count);
            used[col] = false;
            used[diag1] = false;
            used[diag2] = false;
        }
    }
};