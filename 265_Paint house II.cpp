class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<int> currCost(costs[0]);
        vector<int> prevCost(currCost);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) 
                prevCost[j] = currCost[j];
            int minPrevCost = prevCost[0];
            for (int j = 1; j < k; ++j) {
                currCost[j] = minPrevCost + costs[i][j];
                minPrevCost = min(minPrevCost, prevCost[j]);
            }
            minPrevCost = prevCost.back();
            for (int j = k - 2; j > 0; --j) {
                currCost[j] = min(currCost[j], minPrevCost + costs[i][j]);
                minPrevCost = min(minPrevCost, prevCost[j]);
            }
            currCost[0] = minPrevCost + costs[i][0];
        }
        return *min_element(currCost.begin(), currCost.end());
    }
};