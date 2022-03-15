class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        vector<vector<pair<int, int>>> vec(2000);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                vec[dist].push_back({i, j});
            }
        }
        vector<int> ans(n, -1);
        vector<bool> used(m, false);
        for (int d = 0; d < 2000; ++d) {
            sort(vec[d].begin(), vec[d].end());
            for (auto& p : vec[d]) {
                if (ans[p.first] == -1 && !used[p.second]) {
                    ans[p.first] = p.second;
                    used[p.second] = true;
                }
            }
        }
        return ans;
    }
};