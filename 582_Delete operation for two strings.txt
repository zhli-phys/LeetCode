class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return helper(0, 0, word1, word2, dp);
    }
    
    int helper(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        int m = word1.size();
        int n = word2.size();
        if (dp[i][j] >= 0)
            return dp[i][j];
        if (i == m) 
            dp[i][j] = n - j;
        else if (j == n) 
            dp[i][j] = m - i;
        else if (word1[i] == word2[j])
            dp[i][j] = helper(i+1, j+1, word1, word2, dp);
        else 
            dp[i][j] = min(helper(i+1, j, word1, word2, dp), helper(i, j+1, word1, word2, dp)) + 1;
        return dp[i][j];
    }
};