class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < m; ++i) {
            int num = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1)
                    ++num;
                else
                    break;
            }
            vec.push_back({num, i});
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i)
            ans.push_back(vec[i].second);
        return ans;
    }
};