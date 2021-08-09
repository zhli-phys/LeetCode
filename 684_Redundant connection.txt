//union-find; O(n \alpha(n)) 8 ms 73%; O(n) 8.8 MB 65%
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        for (auto& edge : edges) {
            if (find(edge[0], parent) == find(edge[1], parent))
                return edge;
            join(edge[0], edge[1], parent);
        }
        return {0, 0};
    }
    
    int find(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        else {
            parent[i] = find(parent[i], parent);
            return parent[i];
        }
    }
    
    void join(int i, int j, vector<int>& parent) {
        parent[find(i, parent)] = find(j, parent);
    }
};










//deep-first search; O(n^2) 12 ms 32%; O(n^2) 10.7 MB 15%
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<unordered_set<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        for (int i = n - 1; i >= 0; --i) {
            auto& edge = edges[i];
            graph[edge[0]].erase(edge[1]);
            graph[edge[1]].erase(edge[0]);
            vector<bool> visited(n + 1);
            if (dfs(edge[0], edge[1], graph, visited))
                return edge;
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        return {0, 0};
    }
    
    bool dfs(int start, int target, vector<unordered_set<int>>& graph, vector<bool>& visited) {
        if (start == target)
            return true;
        visited[start] = true;
        auto& next = graph[start];
        for (auto it = next.begin(); it != next.end(); ++it) {
            if (!visited[*it] && dfs(*it, target, graph, visited))
                return true;
        }
        visited[start] = false;
        return false;
    }
};