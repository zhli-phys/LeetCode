class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<vector<int>> mp(16);
        for (int i = 0; i < n; i++) 
            mp[words[i].size()-1].push_back(i);
        vector<int> dp(n);
        for (int i = 15; i >= 0; i--) {
            int m = mp[i].size();
            for (int j = 0; j < m; j++) {
                dp[mp[i][j]] = 1;
                if (i < 15) {
                    int l = mp[i+1].size();
                    for (int k = 0; k < l; k++) {
                        if (chain(words[mp[i][j]], words[mp[i+1][k]])) 
                            dp[mp[i][j]] = max(dp[mp[i][j]], 1+dp[mp[i+1][k]]);
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    
    bool chain(string& s1, string& s2) {
        if (s1.size() != s2.size() - 1)
            return false;
        bool add = false;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (!add && s1[i] != s2[i])
                add = true;
            if (add && s1[i] != s2[i+1])
                return false;
        }
        return true;
    }
};
















class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<int, vector<int>> words_with_len;
        size_t n = words.size();
        for (size_t i = 0; i < n; ++i)
            words_with_len[words[i].size()].push_back(i);
        vector<int> dp(n);
        int ans = 0;
        for (size_t i = 0; i < n; ++i)
            ans = max(ans, dfs(i, words, dp, words_with_len));
        return ans;
    }
    
    int dfs(int i, vector<string>& words, vector<int>& dp, unordered_map<int, vector<int>>& words_with_len) {
        if (dp[i] > 0)
            return dp[i];
        int n = words[i].size();
        int ans = 1;
        auto& next = words_with_len[n+1];
        for (int j : next) {
            if (isPredecessor(words[i], words[j]))
                ans = max(ans, 1 + dfs(j, words, dp, words_with_len));
        }
        dp[i] = ans;
        return ans;
    }
    
    bool isPredecessor(const string& s1, const string& s2) {
        size_t n = s1.size();
        if (s2.size() != n + 1)
            return false;
        bool flag = false;
        for (size_t i = 0, j = 0; i < n; ++i, ++j) {
            if (s1[i] != s2[j]) {
                if (flag)
                    return false;
                flag = true;
                --i;
            }
        }
        return true;
    }
};