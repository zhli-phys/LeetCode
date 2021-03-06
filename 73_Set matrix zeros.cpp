class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> rowZero(m);
        vector<bool> colZero(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rowZero[i] = true;
                    colZero[j] = true;
                }
            }
        }
        for (int i = 0; i < m; ++i) 
            if (rowZero[i]) 
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = 0;
        for (int j = 0; j < n; ++j) 
            if (colZero[j])
                for (int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
    }
};









class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> zero_cols(n, false);
        for (int i = 0; i < m; i++) {
            bool zero = false;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zero = true;
                    zero_cols[j] = true;
                }
            }
            if (zero) {
                for (int k = 0; k < n; k++) {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            if (zero_cols[j]) {
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
    }
};