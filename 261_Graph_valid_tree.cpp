class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1)
            return false;
        vector<unordered_set<int>> edg(n);
        for (auto& edge : edges) {
            edg[edge[0]].insert(edge[1]);
            edg[edge[1]].insert(edge[0]);
        }
        vector<bool> seen(n);
        dfs(0, seen, edg);
        for (int i = 0; i < n; ++i)
            if (!seen[i])
                return false;
        return true;
    }
    
    void dfs(int i, vector<bool>& seen, vector<unordered_set<int>>& edg) {
        if (seen[i])
            return;
        seen[i] = true;
        for (int next : edg[i]) 
            dfs(next, seen, edg);
    }
};