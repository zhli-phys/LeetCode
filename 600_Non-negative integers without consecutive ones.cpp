class Solution {
public:
    int findIntegers(int n) {
        vector<vector<int>> dp(2, vector<int>(32));
        dp[0][0] = 1;
        dp[1][0] = 1;
        for (int i = 1; i < 32; ++i) {
            dp[0][i] = dp[1][i-1] + dp[0][i-1];
            dp[1][i] = dp[0][i-1];
        }
        vector<int> bits;
        while (n > 0) {
            bits.push_back(n % 2);
            n /= 2;
        }
        int len = bits.size();
        vector<vector<int>> DP(2, vector<int>(len));
        DP[0][0] = 1;
        if (bits[0] == 1)
            DP[1][0] = 1;
        for (int i = 1; i < len; ++i) {
            if (bits[i] == 1) {
                DP[0][i] = dp[0][i];
                DP[1][i] = DP[0][i-1];
            }
            else 
                DP[0][i] = DP[0][i-1] + DP[1][i-1];
        }
        return DP[1].back() + DP[0].back();
    }
};