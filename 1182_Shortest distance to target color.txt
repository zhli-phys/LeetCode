//O(n) 380 ms 46%; O(n) 138.8 MB 37%
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> distance(n, vector<int>(3, INT_MAX));
        vector<int> pos(3, -1);
        for (int i = 0; i < n; ++i) {
            pos[colors[i]-1] = i;
            for (int j = 0; j < 3; ++j) 
                if (pos[j] >= 0) 
                    distance[i][j] = min(distance[i][j], i - pos[j]);
        }
        for (int j = 0; j < 3; ++j)
            pos[j] = -1;
        for (int i = n - 1; i >= 0; --i) {
            pos[colors[i]-1] = i;
            for (int j = 0; j < 3; ++j)
                if (pos[j] >= 0)
                    distance[i][j] = min(distance[i][j], pos[j] - i);
        }
        vector<int> ans;
        for (auto& query : queries)
            ans.push_back(distance[query[0]][query[1]-1] == INT_MAX ? -1 : distance[query[0]][query[1]-1]);
        return ans;
    }
};