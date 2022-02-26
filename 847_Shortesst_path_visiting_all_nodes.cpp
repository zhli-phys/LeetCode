class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<unordered_set<int>> visited(n);
        int step = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i].insert(1 << i);
        }
        int end = (1 << n) - 1;
        while (!q.empty()) {
            ++step;
            int m = q.size();
            for (int j = 0; j < m; ++j) {
                int i = q.front().first;
                int bitmask = q.front().second;
                q.pop();
                for (int next : graph[i]) {
                    int newBitmask = bitmask | (1 << next);
                    if (newBitmask == end)
                        return step;
                    if (!visited[next].count(newBitmask)) {
                        q.push({next, newBitmask});
                        visited[next].insert(newBitmask);
                    }
                }
            }
        }
        return 0;
    }
};