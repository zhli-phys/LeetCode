class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool flag1 = true;
        bool flag2 = true;
        bool flag3 = true;
        bool flag4 = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (target[i][j] != mat[i][j])
                    flag1 = false;
                if (target[i][j] != mat[j][n-1-i])
                    flag2 = false;
                if (target[i][j] != mat[n-1-i][n-1-j])
                    flag3 = false;
                if (target[i][j] != mat[n-1-j][i])
                    flag4 = false;
            }
        }
        return flag1 || flag2 || flag3 || flag4;
    }
};