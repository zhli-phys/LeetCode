//172 ms 50%; 54.3 MB 13%
class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        int ans = 0;
        unordered_map<int, unordered_map<int, int>> edges;
        for (auto& pipe : pipes) {
            if (edges.find(pipe[0]-1) == edges.end() 
                || edges[pipe[0]-1].find(pipe[1]-1) == edges[pipe[0]-1].end()) {
                edges[pipe[0]-1][pipe[1]-1] = pipe[2];
                edges[pipe[1]-1][pipe[0]-1] = pipe[2];
            }
            else {
                edges[pipe[0]-1][pipe[1]-1] = min(edges[pipe[0]-1][pipe[1]-1], pipe[2]);
                edges[pipe[1]-1][pipe[0]-1] = min(edges[pipe[1]-1][pipe[0]-1], pipe[2]);
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i)
            pq.push({wells[i], i});
        vector<int> visited(n, false);
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            if (!visited[curr.second]) {
                if (edges.find(curr.second) != edges.end()) {
                    auto& edge = edges[curr.second];
                    for (auto it = edge.begin(); it != edge.end(); ++it) {
                        if (!visited[it->first] && it->second <= wells[it->first]) {
                            wells[it->first] = it->second;
                            pq.push({it->second, it->first});
                        }
                    }
                }
                visited[curr.second] = true;
                
            }
        }
        return accumulate(wells.begin(), wells.end(), 0);
    }
};