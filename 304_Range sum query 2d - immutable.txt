class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : sums(matrix.size()+1, vector<int>(matrix[0].size()+1)) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
    
private:
    vector<vector<int>> sums;
};