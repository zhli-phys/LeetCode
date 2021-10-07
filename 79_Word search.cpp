class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {                    
                    if (dfs(i, j, board, 0, word, visited))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board, int k, string& word, vector<vector<bool>>& visited) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || visited[i][j] || board[i][j] != word[k])
            return false;
        if (k == word.size() - 1)
            return true;
        ++k;
        visited[i][j] = true;
        for (auto dir : dirs) {
            if (dfs(i + dir[0], j + dir[1], board, k, word, visited))
                return true;
        }
        visited[i][j] = false;
        return false;
    }
};









class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size();
        int n = board[0].size();
        bool found = false;
        for (int i = 0; i < m; i++) {
            if (found)
                break;
            for (int j = 0; j < n; j++) {
                vector<pair<int, int>> series(0);
                if (exist(board, word, series, i, j, 0)) {
                    found = true;
                    break;
                }
            }
        }
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string& word, vector<pair<int, int>>& series, int i, int j, int pos) {
        if (pos == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (board[i][j] != word[pos]) 
            return false;
        pair<int, int> temp_pair = pair<int, int>(i, j);
        for (int temp = series.size() - 1; temp >= 0; temp--) {
            if (series[temp] == temp_pair)
                return false;
        }
        series.push_back(temp_pair);
        if (exist(board, word, series, i-1, j , pos+1) || exist(board, word, series, i+1, j, pos+1)
                || exist(board, word, series, i, j-1, pos+1) || exist(board, word, series, i, j+1, pos+1)) 
            return true;
        else {
            series.pop_back();
            return false;
        }
    }
};








//Wrong solution! It allows repetition.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        int m = board.size();
        int n = board[0].size();
        vector<int> inner(len, -1);
        vector<vector<int>> middle(n, inner);
        vector<vector<vector<int>>> chart(m, middle);
        bool found = false;
        for (int i = 0; i < m; i++) {
            if (found)
                break;
            for (int j = 0; j < n; j++) {
                if (exist(board, word, chart, i, j, 0)) {
                    found = true;
                    break;
                }
            }
        }
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string& word, vector<vector<vector<int>>>& chart, int i, int j, int pos) {
        if (pos == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (chart[i][j][pos] >= 0)
            return chart[i][j][pos];
        if (board[i][j] != word[pos]) {
            chart[i][j][pos] = 0;
            return false;
        }
        else {
            if (exist(board, word, chart, i-1, j , pos+1) || exist(board, word, chart, i+1, j, pos+1)
                    || exist(board, word, chart, i, j-1, pos+1) || exist(board, word, chart, i, j+1, pos+1)) {
                chart[i][j][pos] = 1;
                return true;
            }
            else {
                chart[i][j][pos] = 0;
                return false;
            }
        }
    }
};