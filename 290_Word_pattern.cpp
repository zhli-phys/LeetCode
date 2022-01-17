class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string mp[26];
        for (int i = 0; i < 26; ++i)
            mp[i] = "";
        unordered_set<string> used;
        int n = pattern.size();
        int idx = 0;
        int m = s.size();
        for (int i = 0; i < n; ++i) {
            if (idx >= m)
                return false;
            int next = idx;
            while (next < m && s[next] != ' ')
                ++next;
            string curr = s.substr(idx, next - idx);
            int pos = pattern[i] - 'a';
            if (mp[pos] == "") {
                if (used.find(curr) != used.end())
                    return false;
                used.insert(curr);
                mp[pos] = curr;
            }
            else if (mp[pos] != curr)
                return false;
            idx = next + 1;
        }
        if (idx < m)
            return false;
        return true;
    }
};












class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> used;
        int n = pattern.size();
        int idx = 0;
        int m = s.size();
        for (int i = 0; i < n; ++i) {
            if (idx >= m)
                return false;
            int next = idx;
            while (next < m && s[next] != ' ')
                ++next;
            string curr = s.substr(idx, next - idx);
            if (mp.find(pattern[i]) == mp.end()) {
                if (used.find(curr) != used.end())
                    return false;
                used.insert(curr);
                mp[pattern[i]] = curr;
            }
            else if (mp[pattern[i]] != curr)
                return false;
            idx = next + 1;
        }
        if (idx < m)
            return false;
        return true;
    }
};