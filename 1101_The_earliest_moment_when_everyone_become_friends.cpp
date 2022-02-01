class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        int groups = n;
        vector<int> parent(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        sort(logs.begin(), logs.end());
        for (auto& log : logs) {
            if (find(log[1], parent) != find(log[2], parent)) {
                unite(log[1], log[2], parent);
                --groups;
                if (groups == 1)
                    return log[0];
            }
        }
        return -1;
    }
    
    int find(int i, vector<int>& parent) {
        if (i != parent[i])
            parent[i] = find(parent[i], parent);
        return parent[i];
    }
    
    void unite(int i, int j, vector<int>& parent) {
        parent[find(i, parent)] = find(j, parent);
    }
};