//time limit exceeded
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        vector<unordered_map<int, int>> dp(dist.size());
        return min_skips(0, dist, speed, hoursBefore, dp);
    }
    
    int min_skips(int i, vector<int>& dist, int speed, int hoursBefore, vector<unordered_map<int, int>>& dp) {
        int dist_sum = accumulate(dist.begin() + i, dist.end(), 0);
        if (static_cast<double>(dist_sum) / speed > hoursBefore)
            return -1;
        int n = dist.size();
        if (i == n - 1)
            return 0;
        if (dp[i].find(hoursBefore) != dp[i].end())
            return dp[i][hoursBefore];
        int curr_dist = 0;
        int ans = n - i - 1;
        for (int j = 1; j < n - i; ++j) {
            curr_dist += dist[i+j-1];
            int curr_min = min_skips(i+j, dist, speed, hoursBefore - ceil(static_cast<double>(curr_dist) / speed), dp);
            if (curr_min >= 0)
                ans = min(ans, j - 1 + curr_min);
        }
        dp[i][hoursBefore] = ans;
        return ans;
    }
};







//time limit exceeced, dp[i][j] means the minimum time to go from node i to the end whit at most j skips
class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<int>> dp(n+1, vector<int>(n));
        for (int i = n - 2; i >= 0; --i) 
            dp[i][0] = dp[i+1][0] + ceil(static_cast<double>(dist[i]) / speed);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i][0];
                int next_dist = 0;
                for (int k = 0; k <= n - 1 - i && k <= j; ++k) {
                    next_dist += dist[i+k];
                    dp[i][j] = min(dp[i][j], static_cast<int>(ceil(static_cast<double>(next_dist) / speed)) + dp[i+k+1][j-k]);
                }
            }
        }
        for (int j = 0; j < n; ++j) 
            if (dp[0][j] <= hoursBefore)
                return j;
        return -1;
    }
};



















//112 ms 20%, 128.5 MB 40%, dp[i][j] is the minimum (time * speed) to attain the node i with j skips, keep the fraction part!
using ll = long long;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<ll>> dp(n+1, vector<ll>(n));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = static_cast<ll>(ceil(static_cast<double>(dp[i-1][0]) / speed)) * speed + dist[i-1];
            for (int j = 1; j < i - 1; ++j)
                dp[i][j] = min(static_cast<ll>(ceil(static_cast<double>(dp[i-1][j]) / speed)) * speed, dp[i-1][j-1]) + dist[i-1];
            if (i >= 2)
                dp[i][i-1] = dp[i-1][i-2] + dist[i-1];
        }
        ll time_before = static_cast<ll>(speed) * hoursBefore;
        for (int j = 0; j < n; ++j)
            if (dp[n][j] <= time_before)
                return j;
        return -1;
    }
};











//136 ms 20%, 128.4 MB 40%, same method as before; remove the ceil function to avoid float error
using ll = long long;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<ll>> dp(n+1, vector<ll>(n));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = (dp[i-1][0] / speed + (dp[i-1][0] % speed > 0)) * speed + dist[i-1];
            for (int j = 1; j < i - 1; ++j)
                dp[i][j] = min((dp[i-1][j] / speed + (dp[i-1][j] % speed > 0)) * speed, dp[i-1][j-1]) + dist[i-1];
            if (i >= 2)
                dp[i][i-1] = dp[i-1][i-2] + dist[i-1];
        }
        ll time_before = static_cast<ll>(speed) * hoursBefore;
        for (int j = 0; j < n; ++j)
            if (dp[n][j] <= time_before)
                return j;
        return -1;
    }
};






//284 ms 20%, 128.5 MB 40%, dp[i][j] is the minimum (time * speed) to attain the node i with AT MOST j skips
using ll = long long;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<ll>> dp(n+1, vector<ll>(n));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = (dp[i-1][0] / speed + (dp[i-1][0] % speed > 0)) * speed + dist[i-1];
            for (int j = 1; j < n; ++j)
                dp[i][j] = min((dp[i-1][j] / speed + (dp[i-1][j] % speed > 0)) * speed, dp[i-1][j-1]) + dist[i-1];
        }
        ll time_before = static_cast<ll>(speed) * hoursBefore;
        for (int j = 0; j < n; ++j)
            if (dp[n][j] <= time_before)
                return j;
        return -1;
    }
};