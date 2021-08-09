//152 ms, 90.7 MB
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        if (n == 2)
            return stones[0] + stones[1];
        vector<int> sums(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += stones[i];
            sums[i] = sum;
        }
        vector<int> dp(n);
        dp[n-1] = sum;
        int pre_max = sums[n-2] - dp[n-1];
        for (int i = n - 2; i > 1; --i) {
            dp[i] = max(sum, pre_max);
            pre_max = max(pre_max, sums[i-1] - dp[i]);
        }
        return max(sum, pre_max);
    }
};






//136 ms, 87.3 MB, use one interger as dp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        if (n == 2)
            return stones[0] + stones[1];
        vector<int> sums(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += stones[i];
            sums[i] = sum;
        }
        int dp = sum;
        int pre_max = sums[n-2] - dp;
        for (int i = n - 2; i > 1; --i) {
            dp = max(sum, pre_max);
            pre_max = max(pre_max, sums[i-1] - dp);
        }
        return max(sum, pre_max);
    }
};













//140 ms, 87.2 MB
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sums(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += stones[i];
            sums[i] = sum;
        }
        int dp = sum;
        for (int i = n - 2; i > 0; --i) 
            dp = max(dp, sums[i] - dp);
        return dp;
    }
};