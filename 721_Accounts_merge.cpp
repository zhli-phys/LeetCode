class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<unordered_set<string>>> emails;
        unordered_map<string, vector<unordered_set<int>>> edges;
        for (auto& account : accounts) {
            int m = account.size();
            auto& name = account[0];
            auto& email = emails[name];
            int len = email.size();
            email.push_back(unordered_set<string>());
            auto& edge = edges[name];
            edge.push_back(unordered_set<int>());
            for (int j = 1; j < m; ++j)
                email.back().insert(account[j]);
            for (int i = 0; i < len; ++i) {
                bool overlap = false;
                for (int j = 1; j < m; ++j) {
                    if (email[i].find(account[j]) != email[i].end()) {
                        overlap = true;
                        break;
                    }
                }
                if (overlap) {
                    edge[i].insert(len);
                    edge[len].insert(i);
                }
            }
        }
        
        unordered_map<string, vector<set<string>>> ans;
        for (auto it = emails.begin(); it != emails.end(); ++it) {
            auto& name = it->first;
            auto& email = it->second;
            auto& edge = edges[name];
            auto& result = ans[name];
            int m = email.size();
            vector<bool> used(m);
            for (int i = 0; i < m; ++i) {
                if (!used[i]) {
                    result.push_back(set<string>());
                    dfs(i, edge, email, result.back(), used);
                }
            }
        }
        
        vector<vector<string>> sol;
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            auto& name = it->first;
            auto& email = it->second;
            for (auto& address : email) {
                sol.push_back({name});
                for (auto& add : address) {
                    sol.back().push_back(add);
                }
            }
        }
        return sol;
    }
    
    void dfs(int i, vector<unordered_set<int>>& edge, vector<unordered_set<string>>& email, 
             set<string>& curr, vector<bool>& used) {
        if (used[i])
            return;
        used[i] = true;
        for (auto& address : email[i])
            curr.insert(address);
        for (int next : edge[i])
            dfs(next, edge, email, curr, used);
    }
};















class DSU {
public:
    DSU (int n) : head(n) {
        for (int i = 0; i < n; i++)
            head[i] = i;
    }
    
    int find(int i) {
        while (head[i] != head[head[i]])
            head[i] = head[head[i]];
        return head[i];
    }
    
    void unite(int i, int j) {
        head[find(i)] = find(j);
    }
    
private:
    vector<int> head;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> id;
        unordered_map<string, string> name;
        DSU dsu(10000);
        int curr_id = 0;
        for (auto&& account: accounts) {
            int n = account.size();
            for (int i = 1; i < n; i++) {
                name[account[i]] = account[0];
                if (!id.count(account[i])) {
                    id[account[i]] = curr_id;
                    curr_id++;
                }
                dsu.unite(id[account[i]], id[account[1]]);
            }
        }
        unordered_map<int, int> mp;
        vector<vector<string>> ans;
        for (auto&& nm : name) {
            int temp = dsu.find(id[nm.first]);
            if (!mp.count(temp)) {
                ans.push_back(vector<string>(1, nm.second));
                ans.back().push_back(nm.first);
                mp[temp] = ans.size() - 1;
            }
            else {
                ans[mp[temp]].push_back(nm.first);
            }
        }
        for (auto&& an : ans)
            sort(an.begin()+1, an.end());
        return ans;
    }
};