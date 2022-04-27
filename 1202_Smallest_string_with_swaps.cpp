class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> par(n);
        for (int i = 0; i < n; ++i)
            par[i] = i;
        for (auto& pair : pairs)
            join(pair[0], pair[1], par);
        
        vector<vector<int>> groups;
        unordered_map<int, int> groupNo;
        for (int i = 0; i < n; ++i) {
            int head = find(i, par);
            if (groupNo.find(head) == groupNo.end()) {
                groupNo[head] = groups.size();
                groups.push_back({i});
            }
            else
                groups[groupNo[head]].push_back(i);
        }
        
        int m = groups.size();
        vector<string> strs(m);
        string ans(n, 0);
        for (int i = 0; i < m; ++i) {
            auto& group = groups[i];
            auto& str = strs[i];
            int len = group.size();
            for (int j = 0; j < len; ++j)
                str.push_back(s[group[j]]);
            sort(str.begin(), str.end());
            for (int j = 0; j < len; ++j)
                ans[group[j]] = str[j];
        }
        return ans;
    }
    
    void join(int i, int j, vector<int>& par) {
        par[find(i, par)] = find(j, par);
    }
    
    int find(int i, vector<int>& par) {
        if (par[i] != i) 
            par[i] = find(par[i], par);
        return par[i];
    }
};















class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        unordered_map<int, unordered_set<int>> edges;
        for (auto& pair : pairs) {
            edges[pair[0]].insert(pair[1]);
            edges[pair[1]].insert(pair[0]);
        }
        
        vector<bool> seen(n);
        vector<vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                groups.push_back({});
                dfs(i, edges, seen, groups.back());
            }
        }
        
        int m = groups.size();
        vector<string> strs(m);
        string ans(n, 0);
        for (int i = 0; i < m; ++i) {
            auto& group = groups[i];
            auto& str = strs[i];
            int len = group.size();
            for (int j = 0; j < len; ++j)
                str.push_back(s[group[j]]);
            sort(group.begin(), group.end());
            sort(str.begin(), str.end());
            for (int j = 0; j < len; ++j)
                ans[group[j]] = str[j];
        }
        return ans;
    }
    
    void dfs(int i, unordered_map<int, unordered_set<int>>& edges, vector<bool>& seen, vector<int>& group) {
        if (seen[i])
            return;
        group.push_back(i);
        seen[i] = true;
        for (int next : edges[i])
            dfs(next, edges, seen, group);
    }
};