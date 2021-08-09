class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        vector<int> left(m, 0);
        vector<int> right(m, m - 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int current_right = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], current_right);
                else {
                    right[j] = m - 1;
                    current_right = j - 1;
                }
            }
            int current_left = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], current_left);
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    current_left = j + 1;
                }
                ans = max(ans, min(height[j], right[j] - left[j] + 1));
            }
        }
        return ans * ans;
    }
};