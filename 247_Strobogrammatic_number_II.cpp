class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        string curr(n, 0);
        vector<string> ans;
        if (n % 2 == 0)
            dfs(n/2, n, curr, ans);
        else {
            int mid = n / 2;
            curr[mid] = '0';
            dfs(mid + 1, n, curr, ans);
            curr[mid] = '1';
            dfs(mid + 1, n, curr, ans);
            curr[mid] = '8';
            dfs(mid + 1, n, curr, ans);
        }
        return ans;
    }
    
    void dfs(int pos, int n, string& curr, vector<string>& ans) {
        if (pos == n)
            ans.push_back(curr);
        else {
            if (pos < n - 1) {
                curr[pos] = '0';
                curr[n-pos-1] = '0';
                dfs(pos + 1, n, curr, ans);
            }
            curr[pos] = '1';
            curr[n-pos-1] = '1';
            dfs(pos + 1, n, curr, ans);
            curr[pos] = '8';
            curr[n-pos-1] = '8';
            dfs(pos + 1, n, curr, ans);
            curr[pos] = '6';
            curr[n-pos-1] = '9';
            dfs(pos + 1, n, curr, ans);
            curr[pos] = '9';
            curr[n-pos-1] = '6';
            dfs(pos + 1, n, curr, ans);
        }
    }
};