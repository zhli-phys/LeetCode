//12 ms 27%, 10.2 MB 36%
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for (int i = 1; i <= n; ++i) 
            for (int j = 0; j < 3; ++j)
                dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + costs[i-1][j];
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
    }
};






//no extra space, 16 ms 5.5%, 9.7 MB 60%
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> prev(3);
        vector<int> curr(3);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) 
                curr[j] = min(prev[(j+1)%3], prev[(j+2)%3]) + costs[i-1][j];
            for (int j = 0; j < 3; ++j)
                prev[j] = curr[j];
        }
        return min(min(curr[0], curr[1]), curr[2]);
    }
};






//no extra space; 8 ms 79%; 9.7 MB 60%
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<int> prev(3);
        vector<int> curr(3);
        for (int i = 0; i < n; ++i) {
            curr[0] = min(prev[1], prev[2]) + costs[i][0];
            curr[1] = min(prev[0], prev[2]) + costs[i][1];
            curr[2] = min(prev[0], prev[1]) + costs[i][2];
            prev[0] = curr[0];
            prev[1] = curr[1];
            prev[2] = curr[2];
        }
        return min(min(curr[0], curr[1]), curr[2]);
    }
};