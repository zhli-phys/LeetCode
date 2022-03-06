#define M 1000000007ll

using ll = long long;

class Solution {
public:
    int countOrders(int n) {
        vector<ll> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) 
            dp[i] = i * (2 * i - 1) * dp[i-1] % M;
        return dp.back();
    }
};