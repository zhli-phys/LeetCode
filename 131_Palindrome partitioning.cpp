class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(0, s, curr, ans);
        return ans;
    }
    
    void dfs(int i, const string& s, vector<string>& curr, vector<vector<string>>& ans) {
        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }            
        for (int j = 1; j <= s.size() - i; ++j) {
            string str = s.substr(i, j);
            if (isPalindrome(str)) {
                curr.push_back(str);
                dfs(i + j, s, curr, ans);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& str) {
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};













class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> palin(n);
        for (int i = 0; i < n; i++) {
            int maxlen = min(i, n-i-1);
            for (int j = 0; j <= maxlen; j++) {
                if (s[i-j] == s[i+j]) {
                    palin[i-j].push_back(2*j+1);
                }
                else
                    break;
            }
        }
        for (int i = 1; i < n; i++) {
            int maxlen = min(i, n-i);
            for (int j = 0; j < maxlen; j++) {
                if (s[i-j-1] == s[i+j])
                    palin[i-j-1].push_back(2*j+2);
                else
                    break;
            }
        }
        vector<vector<vector<string>>> str(n);
        return partition(0, s, palin, str);
    }
    
    vector<vector<string>> partition(int i, string& s, vector<vector<int>>& palin, vector<vector<vector<string>>>& str) {
        vector<vector<string>> ans;
        int n = s.size();
        if (i >= n)
            return vector<vector<string>>(1, vector<string>());
        if (!str[i].empty())
            return str[i];
        for (int j : palin[i]) {
            vector<vector<string>> temp = partition(i+j, s, palin, str);
            for (vector<string> local : temp) {
                vector<string> curr;
                curr.push_back(s.substr(i, j));
                curr.insert(curr.end(), local.begin(), local.end());
                ans.push_back(curr);
            }
        }
        str[i] = ans;
        return ans;
    }
};