class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return score(0, n-1, piles, dp) > 0;
    }
    
    int score(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        if (i == j) {
            dp[i][j] = piles[i];
            return piles[i];
        }
        dp[i][j] = max(piles[i] - score(i+1, j, piles, dp), piles[j] - score(i, j-1, piles, dp));
        return dp[i][j];
    }
};











class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};