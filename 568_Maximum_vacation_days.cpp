class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size();
        int k = days[0].size();
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (flights[i][j])
                    edges[i].push_back(j);
            }
        }
        vector<vector<int>> dp(n, vector<int>(k, -1));
        int ans = vacation(0, 0, edges, days, dp);
        for (int i : edges[0]) {
            if (flights[0][i])
                ans = max(ans, vacation(i, 0, edges, days, dp));
        }
        return ans;
    }
    
    int vacation(int i, int j, vector<vector<int>>& edges, vector<vector<int>>& days, vector<vector<int>>& dp) {       
        if (dp[i][j] >= 0)
            return dp[i][j];
        int k = days[0].size();
        if (j == k - 1) {
            dp[i][j] = days[i][j];
            return dp[i][j];
        }
        int ans = vacation(i, j + 1, edges, days, dp);
        for (int next : edges[i])
            ans = max(ans, vacation(next, j + 1, edges, days, dp));
        ans += days[i][j];
        dp[i][j] = ans;
        return ans;
    }
};