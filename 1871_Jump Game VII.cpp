//time limit exceeded
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        size_t n = s.size();
        vector<bool> dp(n);
        dfs(0, s, dp, minJump, maxJump);
        return dp[n-1];
    }
    
    void dfs(size_t i, const string& s, vector<bool>& dp, int minJump, int maxJump) {
        if (dp[i])
            return;
        dp[i] = true;
        int n = s.size();
        for (size_t j = i + minJump; j <= i + maxJump && j < n; ++j) {
            if (s[j] == '0')
                dfs(j, s, dp, minJump, maxJump);
        }
    }
};










//272 ms
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0')
            return false;
        set<int> candidates;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0')
                candidates.insert(i);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int left = i + minJump;
            int right = i + maxJump;
            if (left <= n - 1 && right >= n - 1)
                return true;
            auto it = candidates.lower_bound(left);
            while (it != candidates.end() && *it <= right) {
                q.push(*it);
                it = candidates.erase(it);
            }
        }
        return false;
    }
};














\\O(n log(n)), 296 ms
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0')
            return false;
        set<int> st;
        st.insert(0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                auto it = st.lower_bound(i - maxJump);
                if (it != st.end() && *it <= i - minJump)
                    st.insert(i);
            }
        }
        return st.find(n-1) != st.end();
    }
};











\\O(n log(n)), 108 ms
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0')
            return false;
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                auto it = lower_bound(vec.begin(), vec.end(), i - maxJump);
                if (it != vec.end() && *it <= i - minJump)
                    vec.push_back(i);
            }
        }
        return vec.back() == n - 1;
    }
};











\\O(n), 40 ms, two pointers
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0')
            return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        int i = 0; 
        int j = 1;
        while (j < n) {
            if (s[j] == '0') {
                if (i >= j - maxJump && i <= j - minJump && dp[i]) {
                    dp[j] = true;
                }
                else {
                    i = max(i, j - maxJump);
                    while (i <= j - minJump && !dp[i])
                        ++i;
                    if (i <= j - minJump && dp[i])
                        dp[j] = true;
                }
            }
            ++j;
        }
        return dp[n-1];
    }
};







\\O(n), 40 ms, two pointers
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0')
            return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        int i = 0; 
        int j = minJump;
        while (j < n) {
            if (s[j] == '0') {
                if (i >= j - maxJump && i <= j - minJump) 
                    dp[j] = true;
                else {
                    i = max(i, j - maxJump);
                    while (i < n && !dp[i])
                        ++i;
                    if (i <= j - minJump)
                        dp[j] = true;
                    else 
                        j = i + minJump - 1;
                }
            }
            ++j;
        }
        return dp[n-1];
    }
};





\\O(n), 60 ms, sliding windows
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s.back() != '0')
            return false;
        vector<bool> dp(n, false);
        dp[0] = true;
        int pre = 0;
        for (int j = minJump; j < n; ++j) {
            pre += dp[j - minJump];
            if (j > maxJump)
                pre -= dp[j - maxJump - 1];
            dp[j] = (pre > 0 && s[j] == '0');
        }
        return dp[n-1];
    }
};