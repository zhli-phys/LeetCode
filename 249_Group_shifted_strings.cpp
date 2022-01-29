class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp;
        for (string& s : strings) {
            if (mp.find(s) != mp.end())
                ans[mp[s]].push_back(s);
            else {
                int n = s.size();
                for (int i = 0; i < 26; ++i) {
                    for (int j = 0; j < n; ++j) {
                        ++s[j];
                        if (s[j] > 'z')
                            s[j] -= 26;
                    }
                    mp[s] = ans.size();
                }
                ans.push_back({s});
            }
        }
        return ans;
    }
};