//490 ms 5%; 19.8 MB 11%
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n = coins.size();
        vector<unordered_map<int, int>> dp(n);
        return methods(amount, 0, coins, dp);
    }
    
    int methods(int amount, int start, vector<int>& coins, vector<unordered_map<int, int>>& dp) {
        if (amount == 0)
            return 1;
        if (start >= coins.size() || amount < coins.back())
            return 0;
        if (dp[start].find(amount) != dp[start].end())
            return dp[start][amount];
        int ans = methods(amount, start+1, coins, dp);
        int new_amount = amount;
        while (new_amount >= coins[start]) {
            new_amount -= coins[start];
            ans += methods(new_amount, start+1, coins, dp);
        }
        dp[start][amount] = ans;
        return ans;
    }
};










//200 ms 5%, 30.7 MB 5%
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n = coins.size();
        vector<unordered_map<int, int>> dp(n);
        return methods(amount, 0, coins, dp);
    }
    
    int methods(int amount, int start, vector<int>& coins, vector<unordered_map<int, int>>& dp) {
        if (amount == 0)
            return 1;
        if (start >= coins.size() || amount < coins.back())
            return 0;
        if (dp[start].find(amount) != dp[start].end())
            return dp[start][amount];
        int ans = methods(amount, start+1, coins, dp) + methods(amount - coins[start], start, coins, dp);
        dp[start][amount] = ans;
        return ans;
    }
};













//use vector instead of hash table; 12 ms 78%; 18.9 MB 16%
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return methods(amount, 0, coins, dp);
    }
    
    int methods(int amount, int start, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) 
            return 1;
        if (start >= coins.size() || amount < coins.back())
            return 0;
        if (dp[start][amount] >= 0)
            return dp[start][amount];
        dp[start][amount] = methods(amount, start+1, coins, dp) + methods(amount - coins[start], start, coins, dp);
        return dp[start][amount];
    }
};









//1-d dp instead of 2-d dp; 11 ms 78%; 7.2 MB 83%
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};