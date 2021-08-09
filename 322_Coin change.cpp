class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cc(amount + 1, -2);
        cc[0] = 0;
        return helper(coins, cc, amount);
    }
    
    int helper(vector<int>& coins, vector<int>& cc, int amount) {
        if (cc[amount] > -2)
            return cc[amount];
        int ans = -1;
        for (int i = 0; i < coins.size(); i++) {
            int temp = amount - coins[i];
            if (temp >= 0) {
                int curr = 1 + helper(coins, cc, temp);
                if (curr > 0) {
                    if (ans == -1)
                        ans = curr;
                    else if (curr < ans)
                        ans = curr;
                }
            }
        }
        cc[amount] = ans;
        return ans;
    }
};