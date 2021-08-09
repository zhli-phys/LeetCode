//Time limit exceeded
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        sort(p.begin(), p.end());
        vector<int> ans;
        for (int i = 0; i <= n - m; i++) {
            string temp = s.substr(i, m);
            sort(temp.begin(), temp.end());
            if (temp == p)
                ans.push_back(i);
        }
        return ans;
    }
};









class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pchars(26, 0);
        vector<int> schars(26, 0);
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        if (n < m)
            return ans;
        for (int i = 0; i < m; i++) {
            pchars[p[i] - 97]++;
            schars[s[i] - 97]++;
        }
        bool agree = true;
        for (int i = 0; i < 26; i++) {
            if (pchars[i] != schars[i]) {
                agree = false;
                break;
            }
        }
        if (agree)
            ans.push_back(0);
        for (int i = 1; i <= n - m ; i++) {
            schars[s[i - 1] - 97]--;
            schars[s[i + m -1] - 97]++;
            agree = true;
            for (int j = 0; j < 26; j++) {
                if (pchars[j] != schars[j]) {
                    agree = false;
                    break;
                }
            }
            if (agree)
                ans.push_back(i);
        }
        return ans;
    }
};