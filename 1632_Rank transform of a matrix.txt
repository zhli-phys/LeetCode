class Solution {
public:   
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<int, unordered_map<int, int>> dsu;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                unite(dsu[matrix[i][j]], i, -j-1);
        map<int, unordered_map<int, vector<pair<int, int>>>> values;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                values[matrix[i][j]][find(dsu[matrix[i][j]], i)].push_back({i, j});
        vector<int> rowRank(m);
        vector<int> colRank(n);
        vector<vector<int>> ans(m, vector<int>(n));
        for (auto& value : values) {
            for (auto& st : value.second) {
                int rank = 1;
                for (auto& pos : st.second) {
                    rank = max(rank, rowRank[pos.first] + 1);
                    rank = max(rank, colRank[pos.second] + 1);
                }
                for (auto& pos : st.second) {
                    rowRank[pos.first] = rank;
                    colRank[pos.second] = rank;
                    ans[pos.first][pos.second] = rank;
                }
            }
        }
        return ans;
    }
    
    int find(unordered_map<int, int>& dsu, int x) {
        if (dsu.find(x) == dsu.end() || dsu[x] == x)
            dsu[x] = x;
        else
            dsu[x] = find(dsu, dsu[x]);
        return dsu[x];
    }

    void unite(unordered_map<int, int>& dsu, int x, int y) {
        dsu[find(dsu, x)] = find(dsu, y);
    }
};