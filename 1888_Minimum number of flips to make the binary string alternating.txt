class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        if (n % 2 == 0) {
            return min(count_flips(0, s, 0, dp), count_flips(0, s, 1, dp));
        }
        else {
            return min(count_flips_one_repeat(0, s, 0, dp), count_flips_one_repeat(0, s, 1, dp));
        }
    }
    
    int count_flips(int i, const string& s, int curr, vector<vector<int>>& dp) {
        int n = s.size();
        if (i >= n)
            return 0;
        if (dp[i][curr] >= 0)
            return dp[i][curr];
        dp[i][curr] = count_flips(i + 1, s, 1 - curr, dp) + (s[i] - '0' != curr);
        return dp[i][curr];
    }
    
    int count_flips_one_repeat(int i, const string& s, int curr, vector<vector<int>>& dp) {
        int n = s.size();
        if (i >= n)
            return 0;
        if (dp[i][curr+2] >= 0)
            return dp[i][curr+2];
        dp[i][curr+2] = min(count_flips_one_repeat(i + 1, s, 1 - curr, dp), count_flips(i + 1, s, curr, dp)) 
                            + (s[i] - '0' != curr);
        return dp[i][curr+2];
    }
};