class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto& mine : mines)
            grid[mine[0]][mine[1]] = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    count = 0;
                else
                    ++count;
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0)
                    count = 0;
                else
                    ++count;
                dp[i][j] = min(dp[i][j], count);
            }
        }
        
        for (int j = 0; j < n; ++j) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == 0)
                    count = 0;
                else
                    ++count;
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            for (int i = n - 1; i >= 0; --i) {
                if (grid[i][j] == 0)
                    count = 0;
                else
                    ++count;
                dp[i][j] = min(dp[i][j], count);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j)
                ans = max(ans, dp[i][j]);
        return ans;
    }
};












class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<set<int>> rows(n);
        vector<set<int>> cols(n);
        for (auto& mine : mines) {
            rows[mine[0]].insert(mine[1]);
            cols[mine[1]].insert(mine[0]);
        }
        for (int i = 0; i < n; ++i) {
            rows[i].insert(-1);
            rows[i].insert(n);
            cols[i].insert(-1);
            cols[i].insert(n);
        }
        int maxOrder = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rows[i].find(j) != rows[i].end())
                    continue;
                auto it = rows[i].lower_bound(j);
                int currOrder = *it - j;
                --it;
                currOrder = min(currOrder, j - *it);
                it = cols[j].lower_bound(i);
                currOrder = min(currOrder, *it - i);
                --it;
                currOrder = min(currOrder, i - *it);
                maxOrder = max(maxOrder, currOrder);
            }
        }
        return maxOrder;
    }
};