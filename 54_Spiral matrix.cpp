class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currDir = 0;
        while (ans.size() < m * n) {
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;
            if (!isValid(i + dir[currDir][0], j + dir[currDir][1], visited))
                currDir = (currDir + 1) % 4;
            i += dir[currDir][0];
            j += dir[currDir][1];
        }
        return ans;
    }
    
    inline bool isValid(int i, int j, vector<vector<bool>>& visited) {
        int m = visited.size();
        int n = visited[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && !visited[i][j];
    }
};










class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans(0);
        if (matrix.empty() || matrix[0].empty())
            return ans;
        int direction = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int total = n * m;
        vector<bool> visited_rows(m, false);
        vector<vector<bool>> visited(n, visited_rows);
        int row = 0;
        int col = 0;
        visited[0][0] = true;;
        ans.push_back(matrix[0][0]);
        for (int i = 1; i < total; i++) {
            if (!move(direction, row, col, visited, ans, matrix))
                move(direction, row, col, visited, ans, matrix);
        }
        return ans;
    }
    
    bool move(int& direction, int& row, int& col, vector<vector<bool>>& visited, vector<int>& ans, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (direction == 0) {
            if (col >= m - 1 || visited[row][col+1]) {
                direction++;
                return false;
            }
            else {
                col++;
                visited[row][col] = true;
                ans.push_back(matrix[row][col]);
                return true;
            }
        }
        else if (direction == 1) {
            if (row >=  n - 1 || visited[row+1][col]) {
                direction++;
                return false;
            }
            else {
                row++;
                visited[row][col] = true;
                ans.push_back(matrix[row][col]);
                return true;
            }
        }
        else if (direction == 2) {
            if (col <= 0 || visited[row][col-1]) {
                direction++;
                return false;
            }
            else {
                col--;
                visited[row][col] = true;
                ans.push_back(matrix[row][col]);
                return true;
            }
        }
        else {
            if (row <= 0 || visited[row-1][col]) {
                direction = 0;
                return false;
            }
            else {
                row--;
                visited[row][col] = true;
                ans.push_back(matrix[row][col]);
                return true;
            }
        }
    }
};