//dynamical programming; O(k * n) 44 ms 42%; O(k * n) 25.4 MB 13%
#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                if (j >= i)
                    dp[i][j] -= dp[i-1][j-i];
                dp[i][j] %= M;
                if (dp[i][j] < 0)
                    dp[i][j] += M;
            }
        }
        return dp[n][k];
    }
};














//compressed dynamical programming; O(n * k) 32 ms 64%; O(k) 6.5 MB 87%
#define M 1000000007ll
using ll = long long;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<ll> dp(k + 1);
        vector<ll> prev(k + 1);
        dp[0] = 1;
        prev[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[j] += dp[j-1];
                if (j >= i)
                    dp[j] -= prev[j-i];
                dp[j] %= M;
                if (dp[j] < 0)
                    dp[j] += M;
            }
            for (int j = 1; j <= k; ++j)
                prev[j] = dp[j];
        }
        return dp[k];
    }
};