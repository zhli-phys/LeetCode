class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                maxLen = 1;
            }
        }
        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxLen = max(maxLen, 1);
            }
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};













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












class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> zeros(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    zeros[i].push_back(j);
                }
            }
            zeros[i].push_back(n);
        }
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0')
                    continue;
                int len = *lower_bound(zeros[i].begin(), zeros[i].end(), j) - j;
                ans = max(ans, 1);
                for (int k = i + 1; k < m; ++k) {
                    if (matrix[i][j] == '0')
                        break;
                    len = min(len, *lower_bound(zeros[k].begin(), zeros[k].end(), j) - j);
                    int side = min(len, (k - i + 1));
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};