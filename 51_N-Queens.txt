class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> path;
        vector<vector<int>> sol;
        solveNQueens(n, path, sol);
        vector<vector<string>> ans;
        string emptypath = "";
        for (int i = 0; i < n; i++)
            emptypath += '.';
        for (vector<int> ph : sol) {
            vector<string> onepattern(n, emptypath);
            for (int i = 0; i < n; i++) 
                onepattern[i][ph[i]] = 'Q';
            ans.push_back(onepattern);
        }
        return ans;
    }
    
    void solveNQueens(int n, vector<int>& path, vector<vector<int>>& sol) {
        int i = path.size();
        if (i >= n) 
            sol.push_back(path);
        unordered_set<int> banned;
        for (int j = 0; j < i; j++) {
            banned.insert(path[j]);
            banned.insert(path[j]+j-i);
            banned.insert(path[j]-j+i);
        }
        for (int k = 0; k < n; k++) {
            if (!banned.count(k)) {
                path.push_back(k);
                solveNQueens(n, path, sol);
                path.pop_back();
            }
        }
    }
};
















class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queens(n, -1);
        for (int i = 0; i < n; ++i)
            dfs(queens, ans, 0, i);
        return ans;
    }
    
    void dfs(vector<int>& queens, vector<vector<string>>& ans, int row, int i) {
        int n = queens.size();
        for (int j = 0; j < row; ++j) {
            if (queens[j] == i || queens[j] == i + row - j || queens[j] == i - row + j) 
                return;
        }
        queens[row] = i;
        if (row == n - 1) {
            vector<string> curr;
            for (int j = 0; j < n; ++j) 
                curr.push_back(string(queens[j] - 0, '.') + 'Q' + string(n - queens[j] - 1, '.'));
            ans.push_back(curr);
        }
        else {
            for (int k = 0; k < n; ++k)
                dfs(queens, ans, row + 1, k);
        }
    }
};