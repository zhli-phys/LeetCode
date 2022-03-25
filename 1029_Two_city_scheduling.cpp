class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> diff;
        for (int i = 0; i < costs.size(); ++i)
            diff.push_back(costs[i][1] - costs[i][0]);
        sort(diff.begin(), diff.end());
        int ans = 0;
        for (auto& cost : costs)
            ans += cost[0];
        for (int i = 0; i < costs.size() / 2; ++i)
            ans += diff[i];
        return ans;
    }
};