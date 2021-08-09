class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profits(n, -1);
        return maxProfit(prices, profits, 0);
    }
    
    int maxProfit(vector<int>& prices, vector<int>& profits, int i) {
        int n = prices.size();
        if (i >= n - 1) 
            return 0;
        if (profits[i] >= 0)
            return profits[i];
        int ans = 0;
        int bought = maxProfit_bought(prices, profits, prices[i], i + 1);
        int wait = maxProfit(prices, profits, i + 1);
        ans = max(bought, wait);
        profits[i] = ans;
        return ans;
    }
    
    int maxProfit_bought(vector<int>& prices, vector<int>& profits, int current_price, int i) {
        int n = prices.size();
        if (i >= n)
            return 0;
        int ans = 0;
        for (int j = i; j < n; j++) {
            int temp = prices[j] - current_price + maxProfit(prices, profits, j + 2);
            if (temp > ans)
                ans = temp;
        }
        return ans;
    }
};









class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sold = INT_MIN;
        int held = INT_MIN;
        int reset = 0;
        for (int i = 0; i < n; i++) {
            int pre_sold = sold;
            sold = held + prices[i];
            held = max(held, reset - prices[i]);
            reset = max(reset, pre_sold);
        }
        return max(sold, reset);
    }
};