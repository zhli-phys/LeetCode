class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(128, -1);
        vector<bool> used(128, false);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (mp[s[i]] == -1) {
                if (!used[t[i]]) {
                    mp[s[i]] = t[i];
                    used[t[i]] = true;
                }
                else
                    return false;
            }
            else if (mp[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
        