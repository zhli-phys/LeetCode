//dynamical programming; 4 ms 98%; 11 MB 20%
#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(maxMove + 1, -1)));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j][0] = 0;
        return paths(m, n, maxMove, startRow, startColumn, dp);
    }
    
    ll paths(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<ll>>>& dp) {
        if (startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n)
            return 1;
        if (dp[startRow][startColumn][maxMove] >= 0)
            return dp[startRow][startColumn][maxMove];
        dp[startRow][startColumn][maxMove] = (paths(m, n, maxMove - 1, startRow - 1, startColumn, dp)
                                             + paths(m, n, maxMove - 1, startRow + 1, startColumn, dp)
                                             + paths(m, n, maxMove - 1, startRow, startColumn - 1, dp)
                                             + paths(m, n, maxMove - 1, startRow, startColumn + 1, dp)) % M;
        return dp[startRow][startColumn][maxMove];
    }
};