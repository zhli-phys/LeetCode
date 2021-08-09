//brute force; O(n!) time limit exceeded
using ll = long long;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        ll len = accumulate(matchsticks.begin(), matchsticks.end(), 0ll);
        if (len % 4 != 0)
            return false;
        len /= 4;
        int n = matchsticks.size();
        ll curr_len = matchsticks[0];
        return dfs(1, curr_len, len, matchsticks);
    }
    
    bool dfs(int bitmask, ll curr_len, ll len, vector<int>& matchsticks) {
        if (curr_len > len) 
            return false;
        else if (curr_len == len)
            curr_len = 0;
        int n = matchsticks.size();
        if (bitmask == ((1 << n) - 1))
            return true;
        for (int i = 1; i < n; ++i) {
            if ((bitmask & (1 << i)) == 0 
                && dfs((bitmask | (1 << i)), curr_len + matchsticks[i], len, matchsticks)) 
                return true;
        }
        return false;
    }
};











//brute force; O(4^n) 1036 ms 7%; O(n) 9.5 MB 91%
using ll = long long;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        ll target_len = accumulate(matchsticks.begin(), matchsticks.end(), 0ll);
        if (target_len % 4 != 0)
            return false;
        target_len /= 4;
        int n = matchsticks.size();
        vector<int> len(4);
        len[0] = matchsticks[0];
        if (len[0] > target_len)
            return false;
        return dfs(1, len, target_len, matchsticks);
    }
    
    bool dfs(int i, vector<int>& len, int target_len, vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (i == n)
            return true;
        for (int j = 0; j < 4; ++j) {
            if (len[j] + matchsticks[i] <= target_len) {
                len[j] += matchsticks[i];
                if (dfs(i + 1, len, target_len, matchsticks))
                    return true;
                len[j] -= matchsticks[i];
            }
        }
        return false;
    }
};











//brute force with sorting; O(4^n) 64%; O(n) 9.6 MB 74%
using ll = long long;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        ll target_len = accumulate(matchsticks.begin(), matchsticks.end(), 0ll);
        if (target_len % 4 != 0)
            return false;
        target_len /= 4;
        int n = matchsticks.size();
        vector<int> len(4);
        len[0] = matchsticks[0];
        if (len[0] > target_len)
            return false;
        return dfs(1, len, target_len, matchsticks);
    }
    
    bool dfs(int i, vector<int>& len, int target_len, vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (i == n)
            return true;
        for (int j = 0; j < 4; ++j) {
            if (len[j] + matchsticks[i] <= target_len) {
                len[j] += matchsticks[i];
                if (dfs(i + 1, len, target_len, matchsticks))
                    return true;
                len[j] -= matchsticks[i];
            }
        }
        return false;
    }
};



















//dynamical programming; O(2^n) 432 ms 14%; O(2^n) 159.3 MB 5%
using ll = long long;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        ll target_len = accumulate(matchsticks.begin(), matchsticks.end(), 0ll);
        if (target_len % 4 != 0)
            return false;
        target_len /= 4;
        int n = matchsticks.size();
        vector<vector<bool>> dead_end(1 << n, vector<bool>(3));
        ll curr_len = matchsticks[0];
        if (curr_len > target_len)
            return false;
        return dfs(1, 0, curr_len, target_len, matchsticks, dead_end);
    }
    
    bool dfs(int bitmask, int sides_done, ll curr_len, ll target_len, 
             vector<int>& matchsticks, vector<vector<bool>>& dead_end) {
        if (curr_len == target_len) {
            ++sides_done;
            curr_len = 0;
        }
        if (sides_done == 3)
            return true;
        if (dead_end[bitmask][sides_done])
            return false;
        int n = matchsticks.size();
        for (int i = 1; i < n; ++i) 
            if ((bitmask & (1 << i)) == 0 && curr_len + matchsticks[i] <= target_len
               && dfs((bitmask | (1 << i)), sides_done, curr_len + matchsticks[i], target_len, matchsticks, dead_end))
                return true;
        dead_end[bitmask][sides_done] = true;
        return false;
    }
};