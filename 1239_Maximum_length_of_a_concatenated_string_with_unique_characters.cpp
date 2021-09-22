class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<bool> used(26);
        int n = arr.size();
        vector<bool> repeat(n);
        for (int i = 0; i < n; ++i) 
            repeat[i] = hasRepeat(arr[i]);
        int curr = 0;
        dfs(0, arr, repeat, used, curr, ans);
        return ans;
    }
    
    void dfs(int i, vector<string>& arr, vector<bool>& repeat, vector<bool>& used, int curr, int& ans) {
        if (i == arr.size()) {
            ans = max(ans, curr);
            return;
        }
        dfs(i + 1, arr, repeat, used, curr, ans);
        if (repeat[i])
            return;
        bool compatible = true;
        for (char ch : arr[i]) {
            if (used[ch-'a']) {
                compatible = false;
                break;
            }
        }
        if (compatible) {
            for (char ch : arr[i])
                used[ch-'a'] = true;
            dfs(i + 1, arr, repeat, used, curr + arr[i].size(), ans);
            for (char ch : arr[i])
                used[ch-'a'] = false;
        }
    }
    
    bool hasRepeat(string& s) {
        vector<bool> seen(26);
        for (char ch : s) {
            if (seen[ch-'a'])
                return true;
            seen[ch-'a'] = true;
        }
        return false;
    }
};