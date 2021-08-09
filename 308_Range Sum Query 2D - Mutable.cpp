class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            vector<int> row(n+1);
            for (int j = 0; j < n; j++)
                row[j+1] = row[j] + matrix[i][j];
            vec.push_back(row);
        }
    }
    
    void update(int row, int col, int val) {
        if (vec.empty() || vec[0].empty())
            return;
        int n = vec[0].size();
        int diff = val - vec[row][col+1] + vec[row][col];
        for (int j = col+1; j < n; j++)
            vec[row][j] = vec[row][j] + diff;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (vec.empty() || vec[0].empty())
            return 0;
        int ans = 0;
        for (int i = row1; i <= row2; i++) 
            ans += (vec[i][col2+1] - vec[i][col1]);
        return ans;
    }
    
private:
    vector<vector<int>> vec;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */