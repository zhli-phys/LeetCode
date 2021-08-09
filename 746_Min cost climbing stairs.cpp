//O(n) 8 ms 47%; O(n) 13.7 MB 46%
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i)
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        return min(dp[n-2], dp[n-1]);
    }
};









//O(n) 8 ms 47%; O(1) 13.6 MB 46%
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        for (int i = 2; i < n; ++i) {
            int curr = min(prev2, prev1) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev2, prev1);
    }
};