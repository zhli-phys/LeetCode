class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> path(m, vector<int>(n, -1));
        int ans = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp = helper(i, j, matrix, path);
                if (temp > ans)
                    ans = temp;
            }
        }
        return ans;
    }
    
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& path) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (path[i][j] > 0)
            return path[i][j];
        int ans = 1;
        if (i > 0 && matrix[i-1][j] > matrix[i][j])
            ans = max(ans, helper(i-1, j, matrix, path) + 1);
        if (i < m-1 && matrix[i+1][j] > matrix[i][j])
            ans = max(ans, helper(i+1, j, matrix, path) + 1);
        if (j > 0 && matrix[i][j-1] > matrix[i][j])
            ans = max(ans, helper(i, j-1, matrix, path) + 1);
        if (j < n-1 && matrix[i][j+1] > matrix[i][j])
            ans = max(ans, helper(i, j+1, matrix, path) + 1);
        path[i][j] = ans;
        return ans;
    }
};