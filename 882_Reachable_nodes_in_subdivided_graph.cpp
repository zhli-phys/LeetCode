class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<int>> reachable(n, vector<int>(n));
        vector<bool> visited(n);
        vector<unordered_map<int, int>> lines(n);
        for (auto& edge : edges) {
            lines[edge[0]][edge[1]] = edge[2];
            lines[edge[1]][edge[0]] = edge[2];
        }
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            if (visited[pq.top().second]) {
                pq.pop();
                continue;
            }
            ++ans;
            auto& curr = pq.top();
            int moves = curr.first;
            int node = curr.second;
            pq.pop();
            visited[node] = true;
            for (auto it = lines[node].begin(); it != lines[node].end(); ++it) {
                reachable[node][it->first] = min(maxMoves - moves, it->second - reachable[it->first][node]);
                ans += reachable[node][it->first];
                if (maxMoves >= moves + it->second + 1 && !visited[it->first])
                    pq.push({moves + it->second + 1, it->first});
            }
        }
        return ans;
    }
};