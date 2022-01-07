class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> edges;
        for (auto& adjacentPair : adjacentPairs) {
            edges[adjacentPair[0]].push_back(adjacentPair[1]);
            edges[adjacentPair[1]].push_back(adjacentPair[0]);
        }
        int start = INT_MIN;
        for (auto& edge : edges) {
            if (edge.second.size() == 1) {
                start = edge.first;
                break;
            }
        }
        vector<int> ans;
        int prev = start;
        int curr = edges[start][0];
        ans.push_back(prev);
        ans.push_back(curr);
        int n = adjacentPairs.size() + 1;
        while (ans.size() < n) {
            for (int next : edges[curr]) {
                if (next != prev) {
                    ans.push_back(next);
                    prev = curr;
                    curr = next;
                    break;
                }
            }
        }
        return ans;
    }
};












//This is a general method that also works even the elements in the original array is not unique
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, unordered_set<int>> edges;
        for (auto& adjacentPair : adjacentPairs) {
            edges[adjacentPair[0]].insert(adjacentPair[1]);
            edges[adjacentPair[1]].insert(adjacentPair[0]);
        }
        bool foundStart = false;
        int start = INT_MIN;
        for (auto& edge : edges) {
            if (edge.second.size() % 2 == 1) {
                foundStart = true;
                start = edge.first;
                break;
            }
        }
        vector<int> ans;
        if (foundStart) {
            dfs(start, edges, ans);
        }
        else {
            dfs(edges.begin()->first, edges, ans);
        }
        return ans;
    }
    
    void dfs(int curr, unordered_map<int, unordered_set<int>>& edges, vector<int>& ans) {
        auto& edge = edges[curr];
        while (!edge.empty()) {
            int next = *edge.begin();
            edge.erase(next);
            edges[next].erase(curr);
            dfs(next, edges, ans);
        }
        ans.push_back(curr);
    }
};