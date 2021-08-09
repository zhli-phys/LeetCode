//48 ms 38%; 18.3 MB 75%
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int max_ind = m + n - 2;
        vector<int> ans;
        for (int ind = 0; ind <= max_ind; ++ind) {
            if (ind % 2 == 0) {
                for (int i = max(0, ind-m+1); i <= ind && i < n; ++i) 
                    ans.push_back(mat[ind-i][i]);
            }
            else {
                for (int i = max(0, ind-n+1); i <= ind && i < m; ++i) 
                    ans.push_back(mat[i][ind-i]);
            }
        }
        return ans;
    }
};