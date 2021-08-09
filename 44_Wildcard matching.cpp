class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            if (s.empty())
                return true;
            else 
                return false;
        }
        int n = s.size();
        int m = p.size();
        string p_new = "";
        p_new += p[0];
        for (int i = 1; i < m; i++) {
            if (p[i] != '*' || p[i] != p[i-1])
                p_new += p[i];
        }
        m = p_new.size();
        vector<int> rows(m + 1, -1);
        vector<vector<int>> table(n + 1, rows);
        table[n][m] = 1;
        return helper(s, p_new, 0, 0, table);
    }
    
    bool helper(string &s, string &p, int i, int j, vector<vector<int>>& table) {
        int n = s.size();
        int m = p.size();
        if (table[i][j] >= 0)
            return table[i][j];
        if (j == m) {
            table[i][j] = 0;
            return false;
        }
        if (i == n) {
            for (int k = j; k < m; k++) {
                if (p[k] != '*') {
                    table[i][j] = 0;
                    return false;
                }
            }
            table[i][j] = 1;
            return true;
        }
        if (p[j] >= 'a') {
            if (s[i] == p[j]) {
                table[i][j] = helper(s, p, i+1, j+1, table);
                return table[i][j];
            }
            else {
                table[i][j] = 0;
                return false;
            }
        }
        else if (p[j] == '?') {
            table[i][j] = helper(s, p, i+1, j+1, table);
            return table[i][j];
        }
        else {
            for (int k = i; k <= n; k++) {
                if (helper(s, p, k, j+1, table)) {
                    table[i][j] = 1;
                    return true;
                }
            }
            table[i][j] = 0;
            return false;
        }
    }
};