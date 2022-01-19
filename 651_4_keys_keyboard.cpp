class Solution {
public:
    int maxA(int n) {
        int dp[n+1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
            for (int j = 3; j < i; ++j) 
                dp[i] = max(dp[i], dp[i-j] * (j-1));
        }
        return dp[n];
    }
};









class Solution {
public:
    int maxA(int n) {
        if (n <= 3)
            return n;
        int dp[n];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for (int i = 4; i < n; ++i) {
            int curr = i - 1;
            for (int j = 3; j <= i / 2; ++j) 
                curr = max(curr, dp[j] * dp[i-j]);
            dp[i] = curr;
        }
        int ans = n;
        for (int i = 2; i < n; ++i) 
            ans = max(ans, i * dp[n-i]);
        return ans;
    }
};