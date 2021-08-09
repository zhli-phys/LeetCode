class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        return searchMatrix(matrix, target, 0, matrix.size(), 0, matrix[0].size());
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target, int up, int down, int left, int right) {
        if (up == down || left == right)
            return false;
        int middle1 = (up + down) / 2;
        int middle2 = (left + right) / 2;
        if (target == matrix[middle1][middle2])
            return true;
        else if (target < matrix[middle1][middle2])
            return (searchMatrix(matrix, target, up, down, left, middle2) ||
                    searchMatrix(matrix, target, up, middle1, middle2, right));
        else
            return (searchMatrix(matrix, target, up, down, middle2 + 1, right) ||
                    searchMatrix(matrix, target, middle1 + 1, down, left, middle2 + 1));
    }
};

















class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = m - 1;
        int col = 0;
        while (matrix[row][col] != target) {
            if (matrix[row][col] < target)
                col++;
            else
                row--;
            if (row < 0 || col >= n)
                return false;
        }
        return true;
    }
};