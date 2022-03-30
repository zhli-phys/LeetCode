class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int num = matrix[mid/n][mid%n];
            if (num == target)
                return true;
            else if (num < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};