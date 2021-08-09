//172 ms, 119.9 MB
#define M 1000000007
using ull = unsigned long long;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<ull>> dp(n + 1, vector<ull>(k + 1));
        dp[1][1] = 1;
        for (int i = 2; i <= n; ++i) 
            for (int j = 1; j <= k; ++j) 
                dp[i][j] = (dp[i-1][j] * (i - 1) + dp[i-1][j-1]) % M;
        return dp[n][k];
    }
};







//92 ms, 6.3 MB, save space
#define M 1000000007
using ull = unsigned long long;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<ull> dp(k+1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            ull prev = dp[0];
            for (int j = 1; j <= k; ++j) {
                ull temp = dp[j];
                dp[j] = (dp[j] * (i - 1) + prev) % M;
                prev = temp;
            }
        }
        return dp[k];
    }
};