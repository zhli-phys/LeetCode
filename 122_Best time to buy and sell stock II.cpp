class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bought = prices[0];
        int profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            if (prices[i] > bought)
                profit += (prices[i] - bought);
            bought = prices[i];
        }
        return profit;
    }
};