class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int sol = 0;
        int current_min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > current_min) 
                sol = max(sol, prices[i] - current_min);
            else
                current_min = prices[i];
        }
        return sol;
    }
};