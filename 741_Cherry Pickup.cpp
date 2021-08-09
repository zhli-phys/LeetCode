//Time limit exceeded
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        return max(helper(0, 0, grid, true), 0);
    }
    
    int helper(int i, int j, vector<vector<int>>& grid, bool forward) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1)
            return -1;
        int curr = grid[i][j];
        grid[i][j] = 0;
        int ans;
        if (forward) {
            if (i == n-1 && j == n-1) {
                ans = curr + helper(i, j, grid, false);
            }
            else {
                int down = helper(i+1, j, grid, true);
                int right = helper(i, j+1, grid, true);
                ans = curr + max(down, right);
            }
        }
        else {
            if (i == 0 && j == 0) {
                ans = curr;
            }
            else {
                int up = helper(i-1, j, grid, false);
                int left = helper(i, j-1, grid, false);
                ans = curr + max(up, left);
            }
        }
        grid[i][j] = curr;
        if (ans == curr-1)
            return -1;
        return ans;
    }
};















class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -2));
        return max(helper(0, 0, grid, dp, true), 0);
    }
    
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, bool forward) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1)
            return -1;
        if (forward && dp[i][j] > -2)
            return dp[i][j];
        int curr = grid[i][j];
        grid[i][j] = 0;
        int ans;
        if (forward) {
            if (i == n-1 && j == n-1) {
                ans = curr + helper(i, j, grid, dp, false);
            }
            else {
                int down = helper(i+1, j, grid, dp, true);
                int right = helper(i, j+1, grid, dp, true);
                ans = curr + max(down, right);
            }
        }
        else {
            if (i == 0 && j == 0) {
                ans = curr;
            }
            else {
                int up = helper(i-1, j, grid, dp, false);
                int left = helper(i, j-1, grid, dp, false);
                ans = curr + max(up, left);
            }
        }
        grid[i][j] = curr;
        if (ans == curr-1)
            return -1;
        if (forward)
            dp[i][j] = ans;
        return ans;
    }
};











class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, vector<pair<int, int>>> currpath(0,  vector<pair<int, int>>());
        vector<pair<int, vector<pair<int, int>>>> path;
        helper(0, 0, grid, currpath, path, true);
        if (path.empty())
            return 0;
        int ans = 0;
        int m = path.size();
        for (int i = 0; i < m; i++) {
            vector<vector<int>> copy(grid);
            for (int j = 0; j < 2*n-1; j++) 
                copy[path[i].second[j].first][path[i].second[j].second] = 0;
            int temp = path[i].first + helper(0, 0, copy, currpath, path, false);
            ans = max(ans, temp);
        }
        return ans;
    }
    
    int helper(int i, int j, vector<vector<int>>& grid, pair<int, vector<pair<int, int>>>& currpath, vector<pair<int, vector<pair<int, int>>>>& path, bool savepath) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == -1)
            return -1;
        int curr = grid[i][j];
        currpath.second.push_back(pair<int, int>(i, j));
        currpath.first += curr;
        grid[i][j] = 0;
        int ans;
        if (i == n-1 && j == n-1) {
            if (savepath)
                path.push_back(currpath);
            ans = curr;
        }
        else {
            int down = helper(i+1, j, grid, currpath, path, savepath);
            int right = helper(i, j+1, grid, currpath, path, savepath);
            ans = curr + max(down, right);
        }
        grid[i][j] = curr;
        currpath.first -= curr;
        currpath.second.pop_back();
        if (ans == curr-1)
            return -1;
        return ans;
    }
};









class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -2)));
        int ans = helper(0, 0, 0, grid, dp);
        if (ans < 0)
            return 0;
        return ans;
    }
    
    int helper(int r1, int c1, int r2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= n || grid[r1][c1] == -1)
            return -1;
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= n || grid[r2][c2] == -1)
            return -1;
        if (dp[r1][c1][r2] > -2)
            return dp[r1][c1][r2];
        int curr1 = grid[r1][c1];
        grid[r1][c1] = 0;
        int curr2 = grid[r2][c2];
        grid[r2][c2] = 0;
        int add;
        if (r1 != n-1 || c1 != n-1) {
            vector<int> a(4);
            a[0] = helper(r1+1, c1, r2+1, grid, dp);
            a[1] = helper(r1+1, c1, r2, grid, dp);
            a[2] = helper(r1, c1+1, r2+1, grid, dp);
            a[3] = helper(r1, c1+1, r2, grid, dp);
            add = (*max_element(a.begin(), a.end()));
        }
        else {
            dp[r1][c1][r2] = curr1;
            return curr1;
        }
        grid[r2][c2] = curr2;
        grid[r1][c1] = curr1;
        if (add == -1) {
            dp[r1][c1][r2] = -1;
            return -1;
        }
        dp[r1][c1][r2] = curr1 + curr2 + add;
        return dp[r1][c1][r2];
    }
};