class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int t = 1; t <= k; ++t)
                dp[i][t] = dp[i+1][t-1];
            int deleted = 0;
            int num = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] != s[i])
                    ++deleted;
                else
                    ++num;
                for (int t = deleted; t <= k && t < n - i; ++t) {
                    int currLen = dp[j+1][t-deleted];
                    if (num == 1)
                        ++currLen;
                    else
                        currLen += 1 + length(num);
                    if (dp[i][t] == 0 || dp[i][t] > currLen)
                        dp[i][t] = currLen;
                }
            }
        }
        return dp[0][k];
    }
    
    inline int length(int num) {
        if (num < 10)
            return 1;
        else if (num < 100)
            return 2;
        else
            return 3;
    }
};