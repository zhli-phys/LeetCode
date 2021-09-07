class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int t1_cost = INT_MAX;
        int t1_profit = 0;
        int t2_cost = INT_MAX;
        int t2_profit = 0;
        for (int i = 1; i < n; ++i) {
            t1_cost = min(t1_cost, prices[i-1]);
            t2_cost = min(t2_cost, prices[i-1] - t1_profit);
            t1_profit = max(t1_profit, prices[i] - t1_cost);
            t2_profit = max(t2_profit, prices[i] - t2_cost);
        }
        return t2_profit;
    }
};










class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> preProfit(n);
        int prePrice = prices[0];
        int currPrice = prePrice;
        for (int i = 1; i < n; ++i) {
            prePrice = min(prePrice, currPrice);
            currPrice = prices[i];
            preProfit[i] = max(preProfit[i-1], currPrice - prePrice);
        }
        
        vector<int> postProfit(n);
        int postPrice = prices.back();
        currPrice = postPrice;
        for (int i = n - 2; i >= 0; --i) {
            postPrice = max(postPrice, currPrice);
            currPrice = prices[i];
            postProfit[i] = max(postProfit[i+1], postPrice - currPrice);
        }
        
        int ans = postProfit[0];
        for (int i = 1; i < n; ++i)
            ans = max(ans, preProfit[i-1] + postProfit[i]);
        return ans;
    }
};