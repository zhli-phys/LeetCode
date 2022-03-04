class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 1, vector<double>(query_row + 1));
        dp[0][0] = poured;
        for (int i = 0; i < query_row; ++i) {
            for (int j = 0; j < query_row; ++j) {
                if (dp[i][j] > 1) {
                    dp[i+1][j] += (dp[i][j] - 1.0) / 2.0;
                    dp[i+1][j+1] += (dp[i][j] - 1.0) / 2.0;
                }
            }
        }
        if (dp[query_row][query_glass] > 1.0)
            return 1.0;
        else
            return dp[query_row][query_glass];
    }
};