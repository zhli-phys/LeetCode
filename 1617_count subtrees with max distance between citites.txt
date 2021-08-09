class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1);
        vector<vector<int>> prev;
        helper(ans, n, 0, edges, prev);
        return ans;
    }
    
    void helper(vector<int>& ans, int n, int curr, vector<vector<int>>& edges, vector<vector<int>>& prev) {
        if (curr < n - 1) {
            helper(ans, n, curr + 1, edges, prev);
            prev.push_back(edges[curr]);
            helper(ans, n, curr + 1, edges, prev);
            prev.pop_back();
        }
        else {
            if (prev.empty())
                return;
            int m = prev.size();
            unordered_set<int> st;
            for (int i = 0; i < m; i++) {
                st.insert(prev[i][0]);
                st.insert(prev[i][1]);
            }
            if (st.size() > m + 1)
                return;
            unordered_map<int, unordered_set<int>> mp;
            for (int i = 0; i < m; i++) {
                mp[prev[i][0]].insert(prev[i][1]);
                mp[prev[i][1]].insert(prev[i][0]);
            }
            int max_len = 0;
            for (auto it = mp.begin(); it != mp.end(); it++) {
                if (it->second.size() == 1) {
                    int curr = *(it->second.begin());
                    int len = 1 + dfs(curr, mp, it->first);
                    max_len = max(max_len, len);
                }
            }
            ans[max_len - 1]++;
        }
    }
    
    int dfs(int curr, unordered_map<int, unordered_set<int>>& mp, int prev) {
        int max_len = 0;
        for (auto it = mp[curr].begin(); it != mp[curr].end(); it++) {
            if (*it != prev) {
                int len = 1 + dfs(*it, mp, curr);
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
















class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> vec(n);
        for (int i = 0; i < n - 1; i++) {
            vec[edges[i][0] - 1].insert(edges[i][1] - 1);
            vec[edges[i][1] - 1].insert(edges[i][0] - 1);
        }
        vector<int> ans(n - 1);
        for (int i = 1; i < (1 << n); i++)
            helper(i, n, vec, ans);
        return ans;
    }
    
    void helper(int i, int n, vector<unordered_set<int>>& vec, vector<int>& ans) {
        unordered_set<int> st;
        for (int j = 0; j < n; j++) {
            if (i % 2 == 1)
                st.insert(j);
            i /= 2;
        }
        if (st.size() <= 1)
            return;
        unordered_set<int> visited;
        queue<int> q;
        q.push(*st.begin());
        int endpoint;
        while (!q.empty()) {
            int curr = q.front();
            visited.insert(curr);
            for (auto it = vec[curr].begin(); it != vec[curr].end(); it++) {
                if (st.count(*it) && !visited.count(*it)) {
                    endpoint = *it;
                    q.push(*it);
                }
            }
            q.pop();
        }
        if (visited.size() < st.size())
            return;
        int maxlen = dfs(endpoint, st, vec, -1);
        ans[maxlen - 1]++;
    }
    
    int dfs(int start, unordered_set<int>& st, vector<unordered_set<int>>& vec, int prev) {
        int maxlen = 0;
        for (auto it = vec[start].begin(); it != vec[start].end(); it++) {
            if (*it != prev && st.count(*it)) {
                int temp = 1 + dfs(*it, st, vec, start);
                maxlen = max(maxlen, temp);
            }
        }
        return maxlen;
    }
};