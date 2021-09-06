class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        vector<int> countNodes(n, 1);
        vector<unordered_set<int>> next(n);
        for (auto& edge : edges) {
            next[edge[0]].insert(edge[1]);
            next[edge[1]].insert(edge[0]);
        }
        ans[0] = buildCount(0, next, countNodes);
        buildDist(0, n, next, countNodes, ans);
        return ans;
    }
    
    int buildCount(int i, vector<unordered_set<int>>& next, vector<int>& countNodes) {
        int ans = 0;
        for (auto it = next[i].begin(); it != next[i].end(); ++it) {
            next[*it].erase(i);
            ans += buildCount(*it, next, countNodes);
            ans += countNodes[*it];
            countNodes[i] += countNodes[*it];
        }
        return ans;
    }
    
    void buildDist(int i, int n, vector<unordered_set<int>>& next, vector<int>& countNodes, vector<int>& ans) {
        for (auto it = next[i].begin(); it != next[i].end(); ++it) {
            ans[*it] = ans[i] + (n - 2 * countNodes[*it]);
            buildDist(*it, n, next, countNodes, ans);
        }
    }
};