class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int m = bikes.size();
        vector<vector<int>> dp(m, vector<int>(1 << m, -1));
        return dfs(0, 0, workers, bikes, dp);
    }
    
    int dfs(int i, int bitmask, vector<vector<int>>& workers, 
            vector<vector<int>>& bikes, vector<vector<int>>& dp) {
        if (i == workers.size())
            return 0;
        if (dp[i][bitmask] >= 0)
            return dp[i][bitmask];
        int m = bikes.size();
        int ans = INT_MAX;
        for (int j = 0; j < m; ++j) {
            if ((1 << j) & bitmask)
                continue;
            int curr = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
            ans = min(ans, curr + dfs(i + 1, bitmask | (1 << j), workers, bikes, dp));
        }
        dp[i][bitmask] = ans;
        return ans;
    }
};













class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<bool> avail(bikes.size(), true);
        int ans = INT_MAX;
        dfs(0, 0, avail, workers, bikes, ans);
        return ans;
    }
    
    void dfs(int curr, int currDist, vector<bool>& avail, 
            vector<vector<int>>& workers, vector<vector<int>>& bikes, int& ans) {
        if (currDist >= ans)
            return;
        else if (curr == workers.size()) {
            ans = currDist;
            return;
        }
        int m = bikes.size();
        for (int i = 0; i < m; ++i) {
            if (!avail[i])
                continue;
            avail[i] = false;
            dfs(curr + 1, 
                currDist + abs(workers[curr][0] - bikes[i][0]) + abs(workers[curr][1] - bikes[i][1]), 
                avail, workers, bikes, ans);
            avail[i] = true;
        }
    }
};