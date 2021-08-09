class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> connect(n);
        vector<bool> visited(n, false);
        for (auto&& edge : edges) {
            connect[edge[0]].insert(edge[1]);
            connect[edge[1]].insert(edge[0]);
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++count;
                dfs(i, connect, visited);
            }
        }
        return count;
    }
    
    void dfs(int i, vector<unordered_set<int>>& connect, vector<bool>& visited) {
        if (visited[i])
            return;
        visited[i] = true;
        for (auto j : connect[i])
            dfs(j, connect, visited);
    }
};









class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        for (auto&& edge : edges) 
            combine(edge, parent);
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) 
            st.insert(find(i, parent));
        return st.size();
    }
    
    void combine(vector<int>& edge, vector<int>& parent) {
        if (find(edge[0], parent) != find(edge[1], parent)) {
            parent[parent[edge[0]]] = parent[edge[1]];
        }
    }
    
    int find(int i, vector<int>& parent) {
        if (i == parent[i])
            return i;
        parent[i] = find(parent[i], parent);
        return parent[i];
    }
};