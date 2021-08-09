class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    for (int right = j; right < m; right++) {
                        if (matrix[i][right] == '0')
                            break;
                        bool all_one = true;
                        for (int low = i; low < n; low++) {
                            for (int temp = j; temp <= right; temp++) {
                                if (matrix[low][temp] == '0') {
                                    all_one = false;
                                    maxarea = max(maxarea, (right - j + 1) * (low - i));
                                    break;
                                }
                            }
                            if (!all_one)
                                break;
                        }
                        if (all_one)
                            maxarea = max(maxarea, (right - j + 1) * (n - i));
                    }
                }
            }
        }
        return maxarea;
    }
};







class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        vector<vector<int>> right(n);
        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            right[i] = temp;
            int current = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    for (int k = j - 1; k >= current; k--) 
                        right[i][k] = j - k;
                    current = j + 1;
                }
            }
            for (int k = m - 1; k >= current; k--) 
                right[i][k] = m - k;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    continue;
                int current = right[i][j];
                for (int low = i; low < n; low++) {
                    current = min(current, right[low][j]);
                    maxarea = max(maxarea, (low - i + 1) * current);
                }
            }
        }
        return maxarea;
    }
};








class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        vector<int> height(m, 0);
        vector<int> left(m, 0);
        vector<int> right(m, m - 1);
        for (int i = 0; i < n; i++) {
            int current_left = 0;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    current_left = j + 1;
                    left[j] = 0;
                    height[j] = 0;
                }
                else {
                    left[j] = max(left[j], current_left);
                    height[j]++;
                }
            }
            int current_right = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '0') {
                    right[j] = m - 1;
                    current_right = j - 1;
                }
                else 
                    right[j] = min(right[j], current_right);
            }
            for (int j = 0; j < m; j++)
                maxarea = max(maxarea, height[j] * (right[j] - left[j] + 1));
        }
        return maxarea;
    }
};