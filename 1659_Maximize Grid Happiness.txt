class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int max_mask = 1;
        for (int i = 0; i < n; i++)
            max_mask *= 3;
        vector<vector<vector<vector<int>>>> dp(m*n+1, vector<vector<vector<int>>>(max_mask, vector<vector<int>>(introvertsCount+1, vector<int>(extrovertsCount+1, -1))));
        return helper(0, 0, m, n, introvertsCount, extrovertsCount, dp, max_mask);
    }
    
    int helper(int pos, int mask, int m, int n, int intro, int extro, vector<vector<vector<vector<int>>>>& dp, int max_mask) {
        if (pos >= m*n)
            return 0;
        if (dp[pos][mask][intro][extro] >= 0)
            return dp[pos][mask][intro][extro];
        int ans = helper(pos+1, (mask*3) % max_mask, m, n, intro, extro, dp, max_mask);
        if (intro > 0) {
            int putintro = 120 + helper(pos+1, (mask*3+1) % max_mask, m, n, intro-1, extro, dp, max_mask);
            int first = mask*3 / max_mask;
            if (first == 1)
                putintro -= 60;
            else if (first == 2)
                putintro -= 10;
            if (pos % n != 0) {
                int last = mask % 3;
                if (last == 1)
                    putintro -= 60;
                else if (last == 2)
                    putintro -= 10;
            }
            ans = max(ans, putintro);
        }
        if (extro > 0) {
            int putextro = 40 + helper(pos+1, (mask*3+2) % max_mask, m, n, intro, extro-1, dp, max_mask);
            int first = mask*3 / max_mask;
            if (first == 1)
                putextro -= 10;
            else if (first == 2)
                putextro += 40;
            if (pos % n != 0) {
                int last = mask % 3;
                if (last == 1)
                    putextro -= 10;
                else if (last == 2)
                    putextro += 40;
            }
            ans = max(ans, putextro);
        }
        dp[pos][mask][intro][extro] = ans;
        return ans;
    }
};