class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
            if (n == 1)
                break;
        }
        return ans;
    }
};









class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int>(n, -2));
        return steps(1, 0, dp, n);
    }
    
    int steps(int count, int copied, vector<vector<int>>& dp, int n) {
        if (count == n)
            return 0;
        else if (count > n)
            return -1;
        if (dp[count][copied] >= -1)
            return dp[count][copied];
        int ans = -1;
        if (copied > 0) {
            int next = steps(count + copied, copied, dp, n);
            if (next >= 0) 
                ans = next + 1;
        }        
        if (count != copied) {
            int next = steps(count, count, dp, n);
            if (next >= 0) {
                if (ans >= 0)
                    ans = min(ans, next + 1);
                else
                    ans = next + 1;
            }
        }        
        dp[count][copied] = ans;
        return ans;
    }
};