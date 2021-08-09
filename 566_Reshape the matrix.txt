//12 ms 53%; 10.7 MB 82%
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int len = m * n;
        if (len != r * c)
            return mat;
        int i = 0; 
        int j = 0;
        int k = 0;
        int l = 0;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int pos = 0; pos < len; ++pos) {
            ans[k][l] = mat[i][j];
            if (j == n - 1) {
                ++i;
                j = 0;
            }
            else
                ++j;
            if (l == c - 1) {
                ++k;
                l = 0;
            }
            else
                ++l;
        }
        return ans;
    }
};











//12 ms 53%; 10.7 MB 82%
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int len = m * n;
        if (len != r * c)
            return mat;
        int k = 0;
        int l = 0;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[k][l] = mat[i][j];
                if (l == c - 1) {
                    ++k;
                    l = 0;
                }
                else
                    ++l;
            }
        }
        return ans;
    }
};