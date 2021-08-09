class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<unordered_set<int>> party(2);
        int n = graph.size();
        for (int i = 0; i < n; i++) {
            if (!graph[i].empty() && !party[0].count(i) && !party[1].count(i) && !dfs(i, 0, party, graph))
                return false;
        }
        return true;
    }
    
    bool dfs(int i, int p, vector<unordered_set<int>>& party, vector<vector<int>>& graph) {
        if (party[p].count(i))
            return true;
        else if (party[!p].count(i))
            return false;
        party[p].insert(i);
        for (auto j : graph[i]) {
            if (!dfs(j, !p, party, graph))
                return false;
        }
        return true;
    }
};











class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1);
        for (int i = 0; i < n; i++) {
            if (dp[i] == -1 && !dfs(i, 0, dp, graph))
                return false;
        }
        return true;
    }
    
    bool dfs(int i, int col, vector<int>& dp, vector<vector<int>>& graph) {
        if (dp[i] != -1)
            return dp[i] == col;
        dp[i] = col;
        for (auto j : graph[i]) {
            if (!dfs(j, !col, dp, graph))
                return false;
        }
        return true;
    }
};