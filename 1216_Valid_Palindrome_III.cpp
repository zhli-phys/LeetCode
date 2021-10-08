class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return remove(0, n-1, s, dp) <= k;
    }
    
    int remove(int i, int j, string &s, vector<vector<int>>& dp) {
        if (dp[i][j] >= 0)
            return dp[i][j];
        if (i >= j) {
            dp[i][j] = 0;
            return 0;
        }
        if (s[i] == s[j]) 
            dp[i][j] = remove(i + 1, j - 1, s, dp);
        else 
            dp[i][j] = min(remove(i + 1, j, s, dp), remove(i, j - 1, s, dp)) + 1;
        return dp[i][j];
    }
};