class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int left = 0;
        int right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (pass(mid, row, col, cells)) 
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
    
    bool pass(int day, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> mat(row, vector<int>(col));
        for (int i = 0; i < day; ++i)
            mat[cells[i][0]-1][cells[i][1]-1] = 1;
        vector<pair<int, int>> path;
        for (int j = 0; j < col; ++j) {
            if (dfs(0, j, path, row, col, mat))
                return true;
        }
        return false;
    }
    
    bool dfs(int i, int j, vector<pair<int, int>>& path, int row, int col, vector<vector<int>>& mat) {
        if (i < 0 || j < 0 || j >= col || mat[i][j] == 1)
            return false;
        if (i == row - 1)
            return true;
        path.push_back({i, j});
        mat[i][j] = 1;
        vector<pair<int, int>> dirs({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        for (auto& dir : dirs) {
            if (dfs(i + dir.first, j + dir.second, path, row, col, mat))
                return true;
        }
        path.pop_back();
        return false;
    }
};