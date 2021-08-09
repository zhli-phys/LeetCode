class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return min_difficulty(0, jobDifficulty, d - 1, dp);
    }
    
    int min_difficulty(int i, vector<int>& jobDifficulty, int d, vector<vector<int>>& dp) {
        if (dp[i][d] >= 0)
            return dp[i][d];
        if (d == 0) {
            dp[i][0] = *max_element(jobDifficulty.begin() + i, jobDifficulty.end());
            return dp[i][0];
        }
        int last = jobDifficulty.size() - d;
        int ans = INT_MAX;
        for (int j = i + 1; j <= last; ++j) {
            int curr = *max_element(jobDifficulty.begin() + i, jobDifficulty.begin() + j);   //can be optimized as in the next solution
            curr += min_difficulty(j, jobDifficulty, d-1, dp);
            ans = min(ans, curr);
        }
        dp[i][d] = ans;
        return ans;
    }
};










//better solution
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d)
            return -1;
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return min_difficulty(0, jobDifficulty, d - 1, dp);
    }
    
    int min_difficulty(int i, vector<int>& jobDifficulty, int d, vector<vector<int>>& dp) {
        if (dp[i][d] >= 0)
            return dp[i][d];
        if (d == 0) {
            dp[i][0] = *max_element(jobDifficulty.begin() + i, jobDifficulty.end());
            return dp[i][0];
        }
        int last = jobDifficulty.size() - d;
        int ans = INT_MAX;
        int curr_max = jobDifficulty[i];
        for (int j = i + 1; j <= last; ++j) {
            curr_max = max(curr_max, jobDifficulty[j-1]);
            ans = min(ans, curr_max + min_difficulty(j, jobDifficulty, d-1, dp));
        }
        dp[i][d] = ans;
        return ans;
    }
};