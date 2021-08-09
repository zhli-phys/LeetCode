//dynamical programming; O(n^2) 172 ms 7%; O(n^2) 109.2 MB 5%
//dp[i][j] means the maximum fuel at the i-th stop with j refuels
using ll = long long;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; ++i)
            pos[i] = stations[i-1][0];
        vector<int> fuels(n + 1);
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
        dp[0][0] = startFuel;
        for (int i = 1; i <= n; ++i) {
            int dist = pos[i] - pos[i-1];
            dp[i][0] = dp[i-1][0] - dist;
            for (int j = 1; j < i; ++j) {
                if (dp[i-1][j-1] >= dist)
                    dp[i][j] = dp[i-1][j-1] - dist + stations[i-1][1];
                dp[i][j] = max(dp[i][j], dp[i-1][j] - dist);
            }
            if (dp[i-1][i-1] >= dist)
                dp[i][i] = dp[i-1][i-1] - dist + stations[i-1][1];
        }
        for (int j = 0; j <= n; ++j) 
            if (dp[n][j] >= target - pos.back())
                return j;
        return -1;
    }
};















//dynamical programming; O(n^2) 96 ms 19%; O(n) 16.3 MB 30%
//dp[i] means the maximum distance we can travel with i refuels
using ll = long long;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<ll> dp(n + 1);
        dp[0] = startFuel;
        for (int i = 1; i <= n; ++i) 
            for (int j = i; j >= 1; --j) 
                if (stations[i-1][0] <= dp[j-1])
                    dp[j] = max(dp[j], dp[j-1] + stations[i-1][1]);
        for (int i = 0; i <= n; ++i)
            if (dp[i] >= target)
                return i;
        return -1;
    }
};














//greedy algorithm using priority_queue; O(n log n) 24 ms 86%; O(n) 16.3 MB 54%
using ll = long long;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        ll dist = startFuel;
        int refuels = 0;
        priority_queue<int> fuels;
        for (auto&& station : stations) {
            while (dist < station[0] && !fuels.empty()) {
                dist += fuels.top();
                fuels.pop();
                ++refuels;
            }
            if (dist < station[0])
                return -1;
            fuels.push(station[1]);
        }
        while (dist < target && !fuels.empty()) {
            dist += fuels.top();
            fuels.pop();
            ++refuels;
        }
        if (dist >= target)
            return refuels;
        else
            return -1;
    }
};