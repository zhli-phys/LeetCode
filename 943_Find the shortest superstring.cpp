//416 ms
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        size_t n = words.size();
        vector<string> updated_words;
        for (size_t i = 0; i < n; ++i) {
            bool flag = false;
            for (size_t j = 0; j < n; ++j) {
                if (j != i && words[j].find(words[i]) != string::npos) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                updated_words.push_back(words[i]);
        }
        n = updated_words.size();
        vector<vector<int>> len(n, vector<int>(n));
        for (size_t i = 0; i < n; ++i) 
            for (size_t j = 0; j < n; ++j)
                update(i, j, updated_words, len);
        vector<size_t> path;
        int length = 0;
        vector<size_t> curr_path;
        int curr_length = 0;
        vector<vector<pair<int, vector<int>>>> dp(n, vector<pair<int, vector<int>>>(1 << n, {-1, vector<int>(0)}));
        int max_length = -1;
        vector<int> max_path;
        for (size_t i = 0; i < n; ++i) {
            dfs(i, len, curr_path, curr_length, dp);
            if (dp[i][0].first > max_length) {
                max_length = dp[i][0].first;
                max_path = dp[i][0].second;
                max_path.push_back(i);
            }
        }
        reverse(max_path.begin(), max_path.end());
        string ans = updated_words[max_path[0]];
        for (size_t i = 1; i < n; ++i) 
            ans += updated_words[max_path[i]].substr(len[max_path[i-1]][max_path[i]]);
        return ans;
    }
    
    void update(size_t i, size_t j, vector<string>& updated_words, vector<vector<int>>& len) {
        if (i == j) 
            return;
        size_t n1 = updated_words[i].size();
        size_t n2 = updated_words[j].size();
        size_t n = min(n1, n2);
        int count = 0;
        for (size_t k = n; k > 0; --k) {
            if (updated_words[i].substr(n1 - k) == updated_words[j].substr(0, k)) {
                len[i][j] = k;
                return;
            }
        }
    }
    
    void dfs(size_t i, vector<vector<int>>& len, vector<size_t>& curr_path, int& curr_length,
            vector<vector<pair<int, vector<int>>>>& dp) {
        size_t bitmask = 0;
        for (size_t p : curr_path)
            bitmask += (1 << p);
        if (dp[i][bitmask].first >= 0)
            return;
        size_t n = len.size();
        int curr = 0;
        if (!curr_path.empty())
            curr = len[curr_path.back()][i];
        curr_length += curr;
        curr_path.push_back(i);
        int remain_length = 0;
        vector<int> remain_path;
        if (curr_path.size() != n) {
            bitmask += (1 << i);
            remain_length = -1;
            for (size_t j = 0; j < n; ++j) {
                if (find(curr_path.begin(), curr_path.end(), j) == curr_path.end()) {
                    dfs(j, len, curr_path, curr_length, dp);
                    if (len[i][j] + dp[j][bitmask].first > remain_length) {
                        remain_length = len[i][j] + dp[j][bitmask].first;
                        remain_path = dp[j][bitmask].second;
                        remain_path.push_back(j);
                    }
                }
            }
            bitmask -= (1 << i);
        }
        curr_path.pop_back();
        curr_length -= curr;
        dp[i][bitmask] = {remain_length, remain_path};
        return;
    }
};














\\56 ms
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        size_t n = words.size();
        vector<string> updated_words;
        for (size_t i = 0; i < n; ++i) {
            bool flag = false;
            for (size_t j = 0; j < n; ++j) {
                if (j != i && words[j].find(words[i]) != string::npos) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                updated_words.push_back(words[i]);
        }
        n = updated_words.size();
        vector<vector<int>> overlap(n, vector<int>(n));
        for (size_t i = 0; i < n; ++i) 
            for (size_t j = 0; j < n; ++j)
                update(i, j, updated_words, overlap);
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        vector<vector<int>> next(n, vector<int>(1 << n, -1));
        int max_length = -1;
        int curr = -1;
        vector<int> max_path;
        for (size_t i = 0; i < n; ++i) {
            dfs(i, overlap, 0, dp, next);
            if (dp[i][0] > max_length) {
                max_length = dp[i][0];
                curr = i;
            }
        }
        vector<size_t> path;
        path.push_back(curr);
        int bitmask = 0;
        while (next[curr][bitmask] >= 0) {
            path.push_back(next[curr][bitmask]);
            bitmask ^= (1 << curr);
            curr = path.back();
        }
        string ans = updated_words[path[0]];
        for (size_t i = 1; i < n; ++i) 
            ans += updated_words[path[i]].substr(overlap[path[i-1]][path[i]]);
        return ans;
    }
    
    void update(size_t i, size_t j, vector<string>& updated_words, vector<vector<int>>& overlap) {
        if (i == j) 
            return;
        size_t n1 = updated_words[i].size();
        size_t n2 = updated_words[j].size();
        size_t n = min(n1, n2);
        int count = 0;
        for (size_t k = n; k > 0; --k) {
            if (updated_words[i].substr(n1 - k) == updated_words[j].substr(0, k)) {
                overlap[i][j] = k;
                return;
            }
        }
    }
    
    void dfs(size_t i, vector<vector<int>>& overlap, int bitmask, vector<vector<int>>& dp, vector<vector<int>>& next) {
        if (dp[i][bitmask] >= 0)
            return;
        size_t n = overlap.size();
        bitmask ^= (1 << i);
        int remain_length = -1;
        int next_node = -1;
        for (size_t j = 0; j < n; ++j) {
            if (!((1 << j) & bitmask)) {
                dfs(j, overlap, bitmask, dp, next);
                if (overlap[i][j] + dp[j][bitmask] > remain_length) {
                    remain_length = overlap[i][j] + dp[j][bitmask];
                    next_node = j;
                }
            }
        }
        bitmask ^= (1 << i);
        dp[i][bitmask] = max(0, remain_length);
        next[i][bitmask] = next_node;
        return;
    }
};










\\56 ms
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        size_t n = words.size();
        vector<vector<int>> overlap(n, vector<int>(n));
        for (size_t i = 0; i < n; ++i) 
            for (size_t j = 0; j < n; ++j)
                update(i, j, words, overlap);
        vector<vector<int>> dp(n, vector<int>(1 << n, -1));
        vector<vector<int>> next(n, vector<int>(1 << n, -1));
        int max_length = -1;
        int curr = -1;
        vector<int> max_path;
        for (size_t i = 0; i < n; ++i) {
            dfs(i, overlap, 0, dp, next);
            if (dp[i][0] > max_length) {
                max_length = dp[i][0];
                curr = i;
            }
        }
        vector<size_t> path;
        path.push_back(curr);
        int bitmask = 0;
        while (next[curr][bitmask] >= 0) {
            path.push_back(next[curr][bitmask]);
            bitmask ^= (1 << curr);
            curr = path.back();
        }
        string ans = words[path[0]];
        for (size_t i = 1; i < n; ++i) 
            ans += words[path[i]].substr(overlap[path[i-1]][path[i]]);
        return ans;
    }
    
    void update(size_t i, size_t j, vector<string>& words, vector<vector<int>>& overlap) {
        if (i == j) 
            return;
        size_t n1 = words[i].size();
        size_t n2 = words[j].size();
        size_t n = min(n1, n2);
        int count = 0;
        for (size_t k = n; k > 0; --k) {
            if (words[i].substr(n1 - k) == words[j].substr(0, k)) {
                overlap[i][j] = k;
                return;
            }
        }
    }
    
    void dfs(size_t i, vector<vector<int>>& overlap, int bitmask, vector<vector<int>>& dp, vector<vector<int>>& next) {
        if (dp[i][bitmask] >= 0)
            return;
        size_t n = overlap.size();
        bitmask ^= (1 << i);
        int remain_length = -1;
        int next_node = -1;
        for (size_t j = 0; j < n; ++j) {
            if (!((1 << j) & bitmask)) {
                dfs(j, overlap, bitmask, dp, next);
                if (overlap[i][j] + dp[j][bitmask] > remain_length) {
                    remain_length = overlap[i][j] + dp[j][bitmask];
                    next_node = j;
                }
            }
        }
        bitmask ^= (1 << i);
        dp[i][bitmask] = max(0, remain_length);
        next[i][bitmask] = next_node;
        return;
    }
};