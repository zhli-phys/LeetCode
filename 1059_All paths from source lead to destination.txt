//dfs; 72 ms 71%; 30.4 MB 65%
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> dir(n);
        for (auto& edge : edges) 
            dir[edge[0]].push_back(edge[1]);
        unordered_set<int> path;
        return dfs(source, destination, path, dir);
    }
    
    bool dfs(int source, int destination, unordered_set<int>& path, vector<vector<int>>& dir) {
        if (dir[source].empty())
            return source == destination;
        path.insert(source);
        for (int next : dir[source]) 
            if (path.find(next) != path.end() || !dfs(next, destination, path, dir))
                return false;
        path.erase(source);
        return true;
    }
};