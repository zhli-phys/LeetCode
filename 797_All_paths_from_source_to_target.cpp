class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(0, curr, graph, ans);
        return ans;
    }
    
    void dfs(int node, vector<int>& curr, vector<vector<int>>& graph, vector<vector<int>>& ans) {
        curr.push_back(node);
        if (node == graph.size() - 1)
            ans.push_back(curr);
        else {
            for (int next : graph[node])
                dfs(next, curr, graph, ans);
        }
        curr.pop_back();
    }
};