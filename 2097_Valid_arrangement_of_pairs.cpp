class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> ingoing;
        unordered_map<int, unordered_set<int>> outgoing;
        for (auto& pair : pairs) {
            ingoing[pair[1]].insert(pair[0]);
            outgoing[pair[0]].insert(pair[1]);
        }
        int start = -1;
        for (auto it = outgoing.begin(); it != outgoing.end(); ++it) {
            if (ingoing.find(it->first) == ingoing.end() || 
                it->second.size() > ingoing[it->first].size()) {
                start = it->first;
                break;
            }
        }
        if (start < 0) {
            start = outgoing.begin()->first;
        }
        vector<vector<int>> ans;
        build(start, outgoing, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void build(int curr, unordered_map<int, unordered_set<int>>& outgoing, vector<vector<int>>& ans) {
        if (outgoing.find(curr) == outgoing.end() || outgoing[curr].empty())
            return;
        while (!outgoing[curr].empty()) {
            int next = *(outgoing[curr].begin());
            outgoing[curr].erase(next);
            build(next, outgoing, ans);
            ans.push_back({curr, next}); 
        }               
    }
};